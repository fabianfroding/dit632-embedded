/* ==================================== 
File name: exerc_3_4.c
Date: 2019-02-15
Group Number:02
Members that contributed:
Fabian
Oliver
Demonstration code: [none] 
====================================== */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define FILENAME_DB "db.bin"
#define PERS_NUM_LEN 13
#define NAME_LEN 20

// PERS NUM FOR TESTING: 198112189876

// -----Typedefs -------
typedef struct
{
    char firstname[NAME_LEN];
    char famnamne[NAME_LEN];
    char pers_number[PERS_NUM_LEN]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
// Using function from exerc_2_7 to validate person number.
bool controlDigit(const char *pNumber)
{
    // Apply Luhn algorithm.
    int nSum = 0;
    int nDigits = strlen(pNumber);
    int nParity = (nDigits - 1) % 2;
    char cDigit[2] = "\0";
    for (int i = nDigits; i > 0; i--)
    {
        cDigit[0] = pNumber[i - 1];
        int nDigit = atoi(cDigit);

        if (nParity == i % 2)
            nDigit = nDigit * 2;

        nSum += nDigit / 10;
        nSum += nDigit % 10;
    }
    return 0 == nSum % 10;
}

// Reads in a person record.
PERSON input_record()
{
    PERSON person;
    printf("\nEnter first name: ");
    gets(person.firstname);
    printf("\nEnter family name: ");
    gets(person.famnamne);
    for (;;)
    {
        printf("\nEnter person number (YYYYMMDDXXXX): ");
        gets(person.pers_number);
        if (controlDigit(person.pers_number + 2))
        {
            break;
        }
        else
        {
            printf("Invalid entry of person number. Try again.");
        }
    }
    return person;
}

// Creates a file and write a first record
void write_new_file(PERSON *inrecord)
{
    FILE *fP;
    fP = fopen(FILENAME_DB, "wb");
    printf("%s\n%s\n%s\n", inrecord->firstname, inrecord->famnamne, inrecord->pers_number);
    fwrite(inrecord, sizeof(PERSON), 1, fP);
    fclose(fP);
}

// print out all persons in the file
void printfile()
{
    FILE *fP;
    fP = fopen(FILENAME_DB, "rb");
    PERSON *person = malloc(sizeof(PERSON));
    printf("//========== Persons\n\n");
    if (fP != NULL)
    {
        for (int i = 0; !feof(fP); ++i)
        {
            if (fread(person, sizeof(PERSON), 1, fP) != 1)
            {
                break;
            }
            printf("%s\n%s\n%s\n\n", person->firstname, person->famnamne, person->pers_number);
        }
    }
    printf("//==========\n");
    fclose(fP);
}

// print out person if in list
void search_by_firstname(char *name)
{
    FILE *fP;
    int matches = 0;
    fP = fopen(FILENAME_DB, "rb");
    PERSON *person = malloc(sizeof(PERSON));
    printf("//========== Search Result:\n\n");
    if (fP != NULL)
    {
        for (int i = 0; !feof(fP); ++i)
        {
            if (fread(person, sizeof(PERSON), 1, fP) != 1)
            {
                break;
            }
            if ((strcmp(person->firstname, name) == 0) || (strcmp(person->famnamne, name) == 0))
            {
                matches++;
                printf("%s\n%s\n%s\n\n", person->firstname, person->famnamne, person->pers_number);
            }
        }
    }
    printf("Found %d matches.\n//==========\n", matches);
    fclose(fP);
}

// appends a new person to the file
void append_file(PERSON *inrecord)
{
    FILE *fP;
    fP = fopen(FILENAME_DB, "ab");
    fwrite(inrecord, sizeof(PERSON), 1, fP);
    fclose(fP);
}

int main()
{
    PERSON ppost;
    char input[1];
    for (;;)
    {
        printf(
            "\nEnter a number for one of the following options:\n\n%s\n%s\n%s\n%s\n%s\n",
            "1 Create a new and delete the old file.",
            "2 Add a new person to the file.",
            "3 Search for a person in the file .",
            "4 Print out all in the file.",
            "5 Exit the program.");
        gets(input);

        if (strcmp(input, "1") == 0)
        {
            strcpy(ppost.firstname, "DummyFirstName");
            strcpy(ppost.famnamne, "DummyFamName");
            strcpy(ppost.pers_number, "198112189876");
            write_new_file(&ppost);
        }
        else if (strcmp(input, "2") == 0)
        {
            ppost = input_record();
            append_file(&ppost);
        }
        else if (strcmp(input, "3") == 0)
        {
            char name[NAME_LEN];
            printf("Enter a first name or family name to search for:\n");
            gets(name);
            search_by_firstname(name);
        }
        else if (strcmp(input, "4") == 0)
        {
            printfile();
        }
        else if (strcmp(input, "5") == 0)
        {
            printf("Goodbye.\n");
            break;
        }
        else
        {
            printf("Unrecognized option.\n");
        }
    }
    return (0);
}
