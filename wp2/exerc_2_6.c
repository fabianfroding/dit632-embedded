// exerc_2_4.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX 5

int main()
{
    int que[MAX];
}

void initQue(int list[], int max)
{
    for (int i = 0; i < max; i++)
    {
        list[i] = -1;
    }
}

int input(int list[], int number, int max)
{
    int arrLength = sizeof(list) / sizeof(int);
    int isFull = false; //boolean
    int success = 1, fail = 0;
    for (int i = 0; i < arrLength; i++)
    {
        /* code */
        if (list[i] == -1)
        {
            list[i] = number;
            return success;
        }
        else if ((i + 1) == arrLength && list[i] != -1)
        {
            return fail;
        }
        else
        {
            return fail;
        }
    }
}
