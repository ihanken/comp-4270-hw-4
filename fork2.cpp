#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/* CONSTANTS */
#define NUM_THREADS 5 // Change this to manipulate thread count.


// This is a function to print Hello World from a given thread.
// The thread is then killed.
void *printHello(void *threadID) {
    long tid = (long) threadID; // Convert to a long for printing.

    printf("Hello, world! It's me, thread #%ld!\n", tid); // Print

    pthread_exit(NULL); // Kill the thread.
}

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS]; // Create an array of threads.

    int rc; // An integer to hold our return code.
    long threadCount = 0; // Keep track of the number of threads we've created.

    for (long i = 0; i < NUM_THREADS; i++) { // Loop through NUM_THREADS/
        for (int j = 0; j < 2; j++) { // Run twice per loop.
            // Instantiate the thread and print from it.
            rc = pthread_create(&threads[i], NULL, printHello, (void*) threadCount);
            threadCount++; // Increment our thread count.

            if (rc) { // If our return code is greater than 0, RIP.
                printf("ERROR, return code from pthread_create() is %d\n", rc);
                exit(-1); // Exit the program early.
            }
        }
    }

    printf("%ld threads were created.\n", threadCount); // Print our final thread count.

    pthread_exit(NULL); // Kill the final thread.
}
