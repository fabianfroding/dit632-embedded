// exerc_2_2.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 20

int main()
{
    //defining arr
    int arr[MAX];
    int *pointer = &arr[0];
    int aInteger;

    //populating arr
    int i;
    srand(time(NULL)); //random num generator

    for (i = 0; i < MAX; i++)
    {
        arr[i] = (rand() % 99 + 1); //from 1 to 99
    }

    int firstValue = arr[0];
    printf("The value of the label array (address) is: %p\n\n", *pointer);            //address
    printf("The first integer in the array is: %d\n", firstValue);                    //first value
    printf("The size of an integer (number of bytes) is: %lu\n", sizeof(firstValue)); //size of first value
    printf("The size of the whole array is: %lu\n", sizeof(arr));                     //array size

    printf("printing array values\n");
    int arrLength = sizeof(arr) / sizeof(int);
    for (int i = 0; i < arrLength; i++)
    {
        printf("[index %d] [value %d] [value doubled %d]\n", i, *pointer, (*pointer * 2));
        pointer++;
    }
}
