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
    void *pointer = arr;
    int aInteger;

    //populating arr
    int i;
    srand(time(NULL)); //random num generator

    for (i = 0; i < MAX; i++)
    {
        arr[i] = (rand() % 99 + 1); //from 1 to 99
    }

    int firstValue = arr[0];
    printf("The value of the label array (address) is: %p\n", &arr);                  //address
    printf("The first integer in the array is (array[0]): %d\n", firstValue);         //first value
    printf("The size of an integer (number of bytes) is: %lu\n", sizeof(firstValue)); //size of first value
    printf("The size of the whole array is: %d\n", sizeof(arr));                      //array size
}
