/* ==================================== 
File name: exerc_3_3.c
Date: 2019-02-15
Group Number:02
Members that contributed:
Fabian
Oliver
Demonstration code: [29366] 
====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Konstanter #####
#define MAX 5

// ##### Typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Funcion declarations #####
REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);

//###### Main program #######
int main(int argc, char *argv[])
{
    int nr = 0;
    REGTYPE *akt_post, *head = NULL;
    srand(time(0)); // Random seed
    head = random_list();
    akt_post = head;
    while (akt_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, akt_post->number);
        akt_post = akt_post->next;
    }

    // --- Free of allocated memory ---
    while ((akt_post = head) != NULL)
    {
        head = akt_post->next;
        free(akt_post);
    }

    //------------------
    return 0;
}

// ==== End of main ======================================
REGTYPE *random_list(void)
{
    int i;
    REGTYPE *prevNode = NULL, *nextNode = NULL, *startNode = NULL;

    for (i = 0; i < MAX; i++)
    {
        REGTYPE *pItem = malloc(sizeof(REGTYPE));
        //assign value to current node
        int randomNumber = rand() % 100;
        (*pItem).number = randomNumber;
        //special case for start node and end node
        if (i == 0)
        { //item is curently at start
            (*pItem).prev = NULL;
            startNode = pItem;
            prevNode = pItem;
        }
        else
        {
            //assign previous nodes nextNode to current node
            (*prevNode).next = pItem;
            //assign current node's previous node to prevNode
            (*pItem).prev = prevNode;
            (*pItem).next = NULL;
            //make current node prev node
            prevNode = pItem;
        }
    }
    return (startNode);
}

//==========================================================
REGTYPE *add_first(REGTYPE *temp, int data)
{
    REGTYPE *pItem = malloc(sizeof(REGTYPE));
    //add number to data structure
    (*pItem).number = data;
    //assign temp node's previous node to current node
    (*temp).prev = pItem;
    //assign current node's next node to temp
    (*pItem).next = temp;
    //assign current node's prev nodes to null
    (*pItem).prev = NULL;

    return (pItem);
}