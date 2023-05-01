// Name: Jake Tsuchiyama
// Date: 9/28/22
// Title: Lab 2 - Step 6
// Description: This program demonstrates a similar concept to Step 1 except it uses threads instead of processes.

/*Sample C program for Lab assignment 1*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
#include <pthread.h>    /* pthread_create, pthread_join */

void* thread1_start(void* n);
void* thread2_start(void* n);

/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pid_t  pid;
    int n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    int *i = malloc(sizeof(*i)); // Allocating memory for start routine parameter
    *i = n;
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL,thread1_start, i); // Create thread 1 with start routine
    pthread_create(&thread2, NULL,thread2_start, i); // Create thread 2 with start routine
    pthread_join(thread1, NULL); // Wait for thread1 to end
    pthread_join(thread2, NULL); // Wait for thread2 to end
    return 0;
}

void* thread1_start(void* n) {
    int i;
    int m = *((int *)n); // Casting back to int
    for(i = 0; i<100; i++) {
        printf("\t \t \t Parent Process %d \n",i);
        usleep(m);
    }
}

void* thread2_start(void* n) {
    int i;
    int m = *((int *)n); // Casting back to int
    for(i = 0; i<100; i++) {
        printf("Child process %d\n",i);
        usleep(m);
    }
}

