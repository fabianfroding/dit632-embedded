#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stddef.h>
#include <pthread.h>
#include <time.h>
#include <math.h>

int program_time = 0; // The global time, start value 0
double last_val;
time_t now;
struct tm *tm;

void *time_count(void *param);
void *read_inport(void *param);

// -------- Function get_time_ms --------------------
double get_time_ms() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}

int get_time_sec() {
    now = time(0);
    if ((tm = localtime (&now)) == NULL) {
        printf ("Error extracting time stuff\n");
        return 0.0;
    }

    /* printf ("%04d-%02d-%02d %02d:%02d:%02d\n",
        tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
        tm->tm_hour, tm->tm_min, tm->tm_sec); */

    return (double)tm->tm_sec;
}

void delay(int number_of_seconds) {
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds; 
    // Stroing start time
    clock_t start_time = clock(); 
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ;
}

// ------------ End -------------------
int main() {
    // Start up the thread time_count.
    pthread_t timeCountThread;
    pthread_create(&timeCountThread, NULL, time_count, NULL);

    printf("\n%f", get_time_ms()/10000000);
    
    // Start up the thread read_inport.
    //pthread_t readInportThread;
    //pthread_create(&readInportThread, NULL, read_inport, NULL);
    
    /*
    while (program_time < 50) {
        //Print out system time every second.
        printf("\nSystem time(main): %f", get_time_ms() / 100);
        printf("\nSystem timeTEST: %f", floor(get_time_ms() / 100));
        printf("\nProgram time: %d", program_time);
    }
    */
    
    pthread_join(timeCountThread, NULL);
    printf("\nJoined timeCountThread in main.");
    //pthread_join(readInportThread, NULL);
    //printf("\nJoined readInportThread in main.");
    return 0;
}
// --- End of main thread ------
// ----- Tread functions –
//--------------------------------------------
void *time_count(void *param) {
    printf("\nStarting timeCountThread.");
    while (program_time < 50) {
        // Check system-time (get_time_ms())
        // Increase program_time by one every second.
        //printf("\nSystem time(timeCountThread): %d\tProgram time(timeCoundThread): %d", get_time_ms(), program_time);
        //int time = get_time_sec();
        double time = floor(get_time_ms() / 1000);
        if (time > last_val) {
            printf("\ntime: %f", time);
            printf("\nlast_val: %f", last_val);
            printf("\nprogram_time: %d", program_time);
            program_time++;
        }
        last_val = time;
    }
    // Exit thread;
    printf("\nExiting timeCountThread.");
    pthread_exit(0);
}
//End------------------------------------

void *read_inport(void *param) {
    printf("\nStarting readInportThread.");
    while (program_time < 50) {
        // Read Inport every 5 second. (Simulate this just by print out a text : Reading Inport now)
        printf("\nReading Inport now");
    }
    // Exit thread
    printf("\nExiting readInportThread.");
    pthread_exit(0);
}
//End------------------------------------
