/* ==================================== 
File name: exerc_6_4.c
Date: 2019-03-12
Group Number:02
Members that contributed:
Fabian
Oliver
Demonstration code: [----] 
====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <math.h>

int program_time; // The global time, start value 0
double last_val;
double cTime;
int hasReport;

void *time_count(void *param);
void *read_inport(void *param);

// -------- Function get_time_ms --------------------
double get_time_ms()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}

// ------------ End -------------------
int main()
{
    // Start up the thread time_count.
    pthread_t timeCountThread;
    pthread_create(&timeCountThread, NULL, time_count, NULL);

    // Start up the thread read_inport.
    pthread_t readInportThread;
    pthread_create(&readInportThread, NULL, read_inport, NULL);

    /*while (program_time < 50) {
        //Print out system time every second.
    }*/

    pthread_join(timeCountThread, NULL);
    printf("\nJoined timeCountThread in main.");
    pthread_join(readInportThread, NULL);
    printf("\nJoined readInportThread in main.");
    return 0;
}
// --- End of main thread ------
// ----- Tread functions –
//--------------------------------------------
void *time_count(void *param)
{
    printf("\nStarting timeCountThread.");
    while (program_time < 50)
    {
        // Check system-time (get_time_ms())
        // Increase program_time by one every second.
        cTime = floor(get_time_ms() / 1000);
        if (cTime > last_val)
        {
            //printf("\ntime: %f\nlast_val: %f\nprogram_time: %d", cTime, last_val, program_time);
            printf("\nprogram_time: %d", program_time);
            program_time++;
            hasReport = 0;
        }
        last_val = cTime;
    }
    // Exit thread;
    printf("\nExiting timeCountThread.");
    pthread_exit(0);
}
//End------------------------------------

void *read_inport(void *param)
{
    printf("\nStarting readInportThread.");
    while (program_time < 50)
    {
        // Read Inport every 5 second. (Simulate this just by print out a text : Reading Inport now)
        if (program_time % 5 == 0)
        {
            if (hasReport == 0)
            {
                printf("\nReading Inport now");
                hasReport = 1;
            }
            else
            {
                //hasReport = 0;
            }
        }
    }
    // Exit thread
    printf("\nExiting readInportThread.");
    pthread_exit(0);
}
//End------------------------------------
