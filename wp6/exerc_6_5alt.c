// Skeleton for exercise nr 6 in WP 6 course DIT165.
// File skeleton_wp6_6.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;

// Global buffer and corresponding counters.
char letter = 'a'; //the starting letter
#define MAX 10     //buffer size

unsigned short count = 0;

char buffer[MAX];  // circular buffer
int write_pos = 0; // index for next character to be put in buffer (put)
int read_pos = 0;  // index for next character to be read ( fetch )

int put_flag = 0;
int fetch_flag = 0;

void *put();
void *fetch();

int main()
{
    int i;
    while (1)
    {
    }
}

void *put()
{
    while (1)
    {
        while (fetch_flag == 1)
        {
        }

        put_flag = 1;
        /*starte implementing put*/
        put_flag = 0;
    }
}
void *fetch()
{
    while (1)
    {
        while (put_flag == 1)
        {
        }

        fetch_flag = 1;
        /*starte implementing put*/
        fetch_flag = 0;
    }
}