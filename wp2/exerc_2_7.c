/* ==================================== 
File name: exerc_2_7.c
Date: 2019-02-7
Group Number:02
Members that contributed:
Fabian
Oliver
Demonstration code: [12890] 
====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

bool controlDigit(const char *pNumber)
{
    // Validate length.
    if (strlen(pNumber) > MAX || strlen(pNumber) < MAX)
        //return false;

        // Validate that each char is digit.
        for (int i = 0; i < MAX; i++)
        {
            if (!isdigit(pNumber[i]))
            {
                //printf("Invalid character at [%d]: %c\n", i, pNumber[i]); // TEST
                return false;
            }
        }

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

void readPersnr(char *person)
{
    for (;;)
    {
        printf("Enter a person number or q to exit.\n");
        gets(person);

        if (strcmp(person, "q") == 0)
        {
            printf("Goodbye.\n");
            break;
        }
        else
        {
            if (controlDigit(person))
                printf("Valid.\n\n");
            else
                printf("Invalid.\n\n");
        }
    }
}

int main()
{
    char input[MAX];
    readPersnr(input);
}