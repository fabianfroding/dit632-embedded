// exerc_2_4.c
//code = 11968
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX 20

int main()
{
    char word[MAX];
    printf("enter word\n");
    fgets(word, 20, stdin);
    printf("your word is %s", word);
    int i;
    int start, end, arrLength;
    bool isPal = true;

    arrLength = strlen(word) - 1;
    start = 0;
    end = arrLength - 1;
    printf("arr is %d\n", arrLength);

    if (arrLength % 2 == 0)
    {
        printf("%s is an even number word\n", word);
        while (start < end)
        {
            if (word[start] == word[end])
            {
                isPal = true;
            }
            else
            {
                isPal = false;
                break;
            }
            ++start;
            --end;
        }
    }
    else
    {
        printf("%s is an odd number word\n", word);
        while (start <= end)
        {
            if (word[start] == word[end])
            {
                isPal = true;
            }
            else
            {
                isPal = false;
                break;
            }
            ++start;
            --end;
        }
    }

    if (isPal)
    {
        printf("the word %s IS a palindrome", word);
    }
    else
    {
        printf("the word %s IS NOT a palindrome", word);
    }
}