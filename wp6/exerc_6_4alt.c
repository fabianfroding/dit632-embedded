/* ==================================== 
File name: exerc_6_4alt.c
Date: 2019-03-12
Group Number: 02
Members that contributed:
Fabian
Oliver
Demonstration code: [15978] 
====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <math.h>

int program_time; // The global time, start value 0
double last_val;
double last_time;
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

    while (program_time < 50)
    {
        //Print out system time every second.
        // Use last_time to check if program_time has incremented, if it has, then print the program_time and increment last_time by 1.
        if (program_time > last_time)
        {
            printf("\nprogram_time: %d", program_time);
            last_time++;
        }
    }

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
        // Here we use floor from math.h to floor down the value in order to make it comparable to the last_val. Otherwise cTime will always be > last_val (comparing ms).
        // Also, we divide by 1000 to get the number the represents seconds.
        cTime = floor(get_time_ms() / 1000);
        // If the current time in seconds (cTime) is > last value retrieved from the same function, we increment the program time.
        if (cTime > last_val)
        {
            //printf("\ntime: %f\nlast_val: %f\nprogram_time: %d", cTime, last_val, program_time);
            program_time++;
            // Set hasReport to 0 to reset the "boolean" chek for read_inport logic.
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
        // hasReport is a boolean flag logic to prevent the readInport print from printing repeatedly while program time has remainder of 0 from % operator.
        if (hasReport == 0)
        {
            hasReport = 1;
            if (program_time % 5 == 0)
                printf("\nReading Inport now");
        }
    }
    // Exit thread
    printf("\nExiting readInportThread.");
    pthread_exit(0);
}
//End------------------------------------
