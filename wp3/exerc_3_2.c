/* ==================================== 
File name: exerc_3_2.c
Date: 2019-02-15
Group Number:02
Members that contributed:
Fabian
Oliver
Demonstration code: [none] 
====================================== */
#include <stdio.h>

#define SEARCH_NUM 67 // Value to search for in search_number().

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
}

void sort(int number, int tab[])
{
    for (int i = 0; i < number; i++)
    {
        // Set each index in array as temporary min value.
        int min_idx = i;
        // Compare the temp min value with each other value in the array.
        for (int j = i; j < number; j++)
        {
            // If value of iterated index is less then min_idx, set to the index of newly found min value.
            if (tab[j] < tab[min_idx])
                min_idx = j;
        }
        // Swap. Could be made into a separate function using pointers. But meh. KISS.
        int temp = tab[min_idx];
        tab[min_idx] = tab[i];
        tab[i] = temp;
        // Repeat this process for each array element. This is basically selection sort.
    }
}

// Returns index of first occurence of number to search for, if not found, return -1.
int search_number(int number, int tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (tab[i] == number)
        {
            printf("%d found in test[%d].\n", number, i);
            return i;
        }
    }
    printf("%d not found in test[].\n", number);
    return -1;
}

int main()
{
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};

    search_number(SEARCH_NUM, test, sizeof(test) / sizeof(test[0]));

    sort(sizeof(test) / sizeof(test[0]), test);
    printf("\nSorted array:\n");
    printArr(test, sizeof(test) / sizeof(test[0]));

    return 0;
}