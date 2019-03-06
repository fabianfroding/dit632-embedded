#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stddef.h>
#include <pthread.h>

int program_time; // The global time, start value 0
int main() {

    // Start up the thread time_count.
    pthread_t time_count;
    pthread_create(&time_count, NULL, time_count, NULL); // Args: 1: ref to thread struct. 2: pthread attr (NULL if dont have any). 3: function as entry point for new thread. 4: value to send to funct.
    
    // Ensures the main thread will wait until 2nd thread finishes.
    pthread_join(time_count, NULL); //Args: 1: value of struct. 2: ???.

    // Start up the thread read_inport.
    pthread_t read_inport;

    while (program_time < 50) {
        //Print out system time every second.

    }
}
// --- End of main thread ------
// ----- Tread functions –
//--------------------------------------------
void *time_count() {
    printf("\nHello from time_count thread.");
    while (program_time < 50) {
        // Check system-time ( get_time_ms())
        // Increase program_time by one every second.
    }
    // exit thread;
}
//End------------------------------------

void *read_inport() {
    printf("\nHello from read_inport thread.");
    while (program_time < 50) {
        // Read Inport every 5 second. (Simulate this just by print out a text : Reading Inport now)
        printf("Reading Inport now");
    }
    // Exit thread
}
//End------------------------------------

// -------- Function get_time_ms --------------------
double get_time_ms() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}
// ------------ End -------------------
