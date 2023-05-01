// Name: Jake Tsuchiyama
// Date: 10/19/22
// Title: Lab 5 - Sychronization with mutex Locks
// Description: This program uses mutex locks to implement the threadHello.c program from the previous lab

// Thread Sychronization
//To compile this code:
//If using the SCU Linux lab first add #include<fcntl.h>
//Then you're ready to compile.
//To compile just add -lpthread to your gcc command like:
//gcc threadSync.c -lpthread
//gcc threadSync.c -o test -lpthread

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <fcntl.h>

#define NTHREADS 10
pthread_t threads[NTHREADS];
pthread_mutex_t lock; // Declare a lock

void* go(void* arg) { 
   pthread_mutex_lock(&lock); //lock acquire; entry section
   printf("Thread %d Entered Critical Section..\n", (int)arg); //critical section 
   sleep(1); 
   pthread_mutex_unlock(&lock); //lock release; exit section
   return (NULL);
} 

int main() { 
   pthread_mutex_init(&lock, NULL); //Create a lock
   static int i;
   for (i = 0; i < NTHREADS; i++)  
      pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
   for (i = 0; i < NTHREADS; i++) {
      pthread_join(threads[i],NULL);
      printf("\t\t\tThread %d returned \n", i);
   }
   printf("Main thread done.\n");
   pthread_mutex_destroy(&lock); // delete lock
   return 0; 
} 
