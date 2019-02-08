#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define FILENAME_DB "db.txt"

// -----Typedefs -------
typedef struct {
    char firstname[20];
    char famnamne[20];
    char pers_number[13]; // yyyymmddnnnc // Changed from 13 to 12. Why 13?
} PERSON;

// Function declaration (to be extend)
// Using function from exerc_2_7 to validate person number.
bool controlDigit(const char *pNumber) {
    // Apply Luhn algorithm.
    int nSum = 0;
    int nDigits = strlen(pNumber);
    int nParity = (nDigits-1) % 2;
    char cDigit[2] = "\0";
    for (int i = nDigits; i > 0 ; i--) {
        cDigit[0]  = pNumber[i-1];
        int nDigit = atoi(cDigit);

        if (nParity == i % 2)
            nDigit = nDigit * 2;

        nSum += nDigit/10;
        nSum += nDigit%10;
    }
    return 0 == nSum % 10;
}

// Reads in a person record.
PERSON input_record() {
    PERSON person;
    printf("\nEnter first name: ");
    gets(person.firstname);
    printf("\nEnter family name: ");
    gets(person.famnamne);
    for (;;) {
        printf("\nEnter person number (YYYYMMDDXXXX): ");
        gets(person.pers_number);
        if (controlDigit(person.pers_number + 2)) {
            break;
        } else {
            printf("Invalid entry of person number. Try again.");
        }
    }
    return person;
}

// Creats a file and write a first record
void write_new_file(PERSON *inrecord) {
    FILE *fPointer;
    fPointer = fopen(FILENAME_DB, "w");
    fprintf(fPointer, "%s\n%s\n%s\n", inrecord -> firstname, inrecord -> famnamne, inrecord -> pers_number);
    fclose(fPointer);
}

// print out all persons in the file
void printfile() {
    FILE *fPointer;
    fPointer = fopen(FILENAME_DB, "r");
    
    char line[20];
    printf("//========== Persons\n\n");
    int lineCount = 0;
    while (fgets(line,50,fPointer) != NULL) {
        printf(line);
        if (lineCount >= 2) {
            printf("\n");
            lineCount = 0;
        } else {
            lineCount++;
        }
    }
    printf("//==========\n");
    
    fclose(fPointer);
}

// print out person if in list
void search_by_firstname(char *name) {

}

// appends a new person to the file
void append_file(PERSON *inrecord) {
    FILE *fPointer;
    fPointer = fopen(FILENAME_DB, "a");
    fprintf(fPointer, "%s\n%s\n%s\n", inrecord -> firstname, inrecord -> famnamne, inrecord -> pers_number);
    fclose(fPointer);
}

int main() {
    PERSON ppost;
    char input[1];
    for (;;) {
        printf(
            "\nEnter a number for one of the following options:\n\n%s\n%s\n%s\n%s\n%s\n", 
            "1 Create a new and delete the old file.",
            "2 Add a new person to the file.",
            "3 Search for a person in the file .",
            "4 Print out all in the file.",
            "5 Exit the program."
        );
        gets(input);

        if (strcmp(input, "1") == 0) {
            ppost = input_record();
            write_new_file(&ppost);
        }
        else if (strcmp(input, "2") == 0) {
            ppost = input_record();
            append_file(&ppost);
        }
        else if (strcmp(input, "3") == 0) {
            char firstName[20];
            search_by_firstname(firstName);
        }
        else if (strcmp(input, "4") == 0) {
            printfile();
        }
        else if (strcmp(input, "5") == 0) {
            printf("Goodbye.\n");
            break;
        }
        else {
            printf("Unrecognized option.\n");
        }
    }
    return(0);
}
