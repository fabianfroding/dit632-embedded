// exerc_2_4.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX 5

void initQue(int list[], int max)
{
    for (int i = 0; i < max; i++)
    {
        list[i] = -1;
    }
}

int input(int list[], int number, int max)
{
    int arrLength = sizeof(list) / sizeof(list[0]);
    int isFull = false; //boolean
    int success = 1, fail = 0;
    int curr = 0, next = curr + 1;
    while (curr < MAX)
    {
        if (list[curr] == -1)
        {
            list[curr] = number;
            return success;
        }
        else
        {
            curr++;
        }
    }
    return fail;
}

int output(int list[], int max)
{ //assumption: this is a "pop" method
    int arrLength = MAX;
    if (isEmpty(list) == true)
    {
        return 0;
    }
    else
    {
        int value = list[0];
        int curr = 0, next = curr + 1;
        int empty = -1;
        while (curr < arrLength)
        {
            printf("current index before change --> %d current value --> %d\n", curr, list[curr]);
            if (next == arrLength)
            {
                list[curr] = empty;
            }
            else if (list[next] == empty)
            {
                //if next is empty
                list[curr] = empty;
            }
            else
            {
                list[curr] = list[next];
            }
            printf("current index after change --> %d new value --> %d\n", curr, list[curr]);
            curr++;
            next = curr + 1;
        }
        return value;
    }
}

int isEmpty(int list[])
{
    int empty = -1, isEmpty = 1, notEmpty = 0;
    if (list[0] == empty)
    {
        return isEmpty;
    }
    else
    {
        return notEmpty;
    }
}

void printList(int list[])
{
    // int arrLength = sizeof(list) / sizeof(list[0]);
    for (int i = 0; i < MAX; i++)
    {
        printf("[%d]", list[i]);
    }
    printf("\n");
}

int main()
{
    int que[MAX];
    initQue(que, MAX);
    printf("initialized list\n");
    printList(que);
    int inputState = input(que, 3, MAX);
    printf("input value %d | input state: %d\n", 3, inputState);
    printList(que);
    inputState = input(que, 4, MAX);
    printf("input value %d | input state: %d\n", 4, inputState);
    printList(que);
    inputState = input(que, 7, MAX);
    printf("input value %d | input state: %d\n", 7, inputState);
    printList(que);
    int outputState = output(que, MAX);
    printf("output state: %d\n", outputState);
    printList(que);
}
