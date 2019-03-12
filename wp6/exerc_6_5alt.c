/* ==================================== 
File name: exerc_6_5.c
Date: 2019-03-12
Group Number:02
Members that contributed:
Fabian
Oliver
Demonstration code: [17055] 
====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global buffer and corresponding counters.
char letter = 'a'; //the starting letter
#define MAX 10     //buffer size
int count = 0;

char buffer[MAX];  // circular buffer
int write_pos = 0; // index for next character to be put in buffer (put)
int read_pos = 0;  // index for next character to be read ( fetch )

pthread_mutex_t flag = PTHREAD_MUTEX_INITIALIZER;
// pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;

void *put();
void *fetch();

void *put()
{
    /**
     * 1. if buffer is full, dont write
     * 2. else 
     * 3. if write_pos = MAX-1 (last spot in buffer), 
     * 3.1 lock mutex
     * 3.2 write to buffer
     * 3.3 set write_pos to 0
     * 3.4 unlock mutex
     * 4. else 
     * 4.1 lock mutex
     * 4.2 write to buffer
     * 4.3 increment write_pos
     * 4.4 unlock mutex
    */

    while (1)
    {
        if (count < MAX) //if buffer is not full
        {
            pthread_mutex_lock(&flag); //lock mutex
            if (write_pos == MAX - 1)
            {
                buffer[write_pos] = letter;
                write_pos = 0;
                count++;
            }
            else
            {
                buffer[write_pos] = letter;
                write_pos++;
                count++;
            }
            printf("Put in: %c", letter);
            if (letter == 'z')
            {
                letter = 'a';
            }
            else
            {
                letter++;
            }
            pthread_mutex_unlock(&flag); //unlock mutex
        }
        else
        {
            printf("FULL\n");
        }
    }
}
void *fetch()
{
    /**
     * 1. if buffer is empty, dont read
     * 2. else 
     * 3. if read_pos = MAX-1 (last spot in buffer), 
     * 3.1 lock mutex
     * 3.2 read from buffer, decrement count
     * 3.3 set read_pos to 0
     * 3.4 unlock mutex
     * 4. else 
     * 4.1 lock mutex
     * 4.2 read from buffer
     * 4.3 increment read_pos, decrement count;
     * 4.3 unlock mutex
    */
    while (1)
    {
        if (count > 0) //if buffer is not empty
        {
            pthread_mutex_lock(&flag);
            if (read_pos == MAX - 1)
            {
                printf("letter\tread_pos\tcount\n");
                printf("%c\t%d\t%d\n", buffer[read_pos], read_pos, count);
                read_pos = 0;
                count--;
            }
            else
            {
                printf("letter\tread_pos\tcount\n");
                printf("%c\t%d\t%d\n", buffer[read_pos], read_pos, count);
                read_pos++;
                count--;
            }
            pthread_mutex_unlock(&flag);
        }
        else
        {
            printf("EMPTY\n");
        }
    }
}

int main()
{

    pthread_t producer, consumer;
    //"put" thread for adding to buffer
    pthread_create(&producer, NULL, put, NULL);
    //"fetch" thread for removing out of buffer
    pthread_create(&consumer, NULL, fetch, NULL);

    while (1)
    {
        printf("Buffer Shop \n");
    }

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
}