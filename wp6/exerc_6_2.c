/* ==================================== 
File name: exerc_6_2.c
Date: 2019-03-12
Group Number: 02
Members that contributed:
Fabian
Oliver
Demonstration code: [13191] 
====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define num_elems 200
int array[200];
int max_value;

void *runner(void *param);
void *sort(void *param);
void *find(void *param);

int main()
{
	printf("\nStarted.\n");

	time_t t;
	pthread_t tid;
	pthread_attr_t attr;

	pthread_t sortThread;
	pthread_attr_t sortAttr;
	pthread_t findThread;
	pthread_attr_t findAttr;

	srand((unsigned)time(&t));
	pthread_attr_init(&attr); // initializes a thread attributes objects with default value for all individual attributes used by a given impl.

	printf("Enter max value\n");
	scanf("%d", &max_value);

	pthread_create(&tid, &attr, runner, NULL); // Args: 1: thread address, 2: thread attributes address (NULL = default), 3: function to be run by thread. 4: arg passed to func.
	pthread_join(tid, NULL);				   // Waits for created thread to finish.
	printf("\nJoined runner thread in main.");

	// Execute sort thread
	pthread_attr_init(&sortAttr);
	pthread_create(&sortThread, &sortAttr, sort, NULL);
	pthread_join(sortThread, NULL);
	printf("\nJoined sortThread in main.");

	// Execute search thread
	pthread_attr_init(&findAttr);
	pthread_create(&findThread, &findAttr, find, NULL);
	pthread_join(findThread, NULL);
	printf("\nJoined findThread in main.");

	return 0;
}

void *runner(void *param)
{
	printf("\nStarting runner thread.");

	for (int i = 0; i < num_elems; i++)
	{
		for (int j = 0; j < 1000; j++)
			; // To delay a bit ???
		array[i] = rand() % max_value;
		printf("\narray[%d]: %d", i, array[i]);
	}

	printf("\nExiting runner thread.");
	pthread_exit(0);
}

void *sort(void *param)
{
	printf("\nStarting sort thread.");
	// SORT
	int swap;
	for (int i = 0; i < num_elems; i++)
	{
		for (int j = 0; j < num_elems - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
			}
		}
	}
	printf("\nExiting sort thread.");
	pthread_exit(0);
}

void *find(void *param)
{
	printf("\nStarting find thread.");
	int search;
	printf("\nEnter value to search for: ");
	scanf("%d", &search);

	int first = 0;
	int last = num_elems - 1;
	int middle = (first + last) / 2;
	for (int i = 0; i < num_elems; i++)
	{
		printf("\narray[%d]: %d", i, array[i]);
	}

	while (first <= last)
	{
		if (array[middle] < search)
		{
			first = middle + 1;
		}
		else if (array[middle] == search)
		{
			printf("\n%d found at location %d.\n", search, middle + 1);
			break;
		}
		else
		{
			last = middle - 1;
		}
		middle = (first + last) / 2;
	}
	if (first > last)
	{
		printf("\nNot found! %d is not present in the list.\n", search);
	}
	printf("\nExiting find thread.");
	pthread_exit(0);
}
