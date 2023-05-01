// Name: Jake Tsuchiyama
// Date: 9/28/22
// Title: Lab 2 - Step 5
// Description: This program creates exactly seven processes.

/*Sample C program for Lab assignment 1*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
/* main function with command-line arguments to pass */
int main() {
    pid_t  pid1, pid2, pid3, pid4;
    printf("\n Before forking.\n");
    printf("Parent %d\n", getpid());
    pid1 = fork();
    if(pid1 == 0) { // Parent' first child
        printf("Child %d of parent %d\n", getpid(), getppid()); 
        pid2 = fork();
        if(pid2 == 0) // First child's first child
            printf("Child %d of parent %d\n", getpid(), getppid()); 
        else {
            pid3 = fork();
            if(pid3 == 0) // First child's second child
                printf("Child %d of parent %d\n", getpid(), getppid()); 
            else
                wait(NULL); // Wait for child
            wait(NULL); // Wait for child
        }
    }

    else {
        pid2 = fork();
        if(pid2 == 0) { // Parent's second child
            printf("Child %d of parent %d\n", getpid(), getppid());
            pid3 = fork();
            if(pid3 == 0) // Second child's first child
                printf("Child %d of parent %d\n", getpid(), getppid());
            else {
                pid4 = fork();
                if(pid4 == 0) // Second child's second child
                    printf("Child %d of parent %d\n", getpid(), getppid());
                else
                    wait(NULL); // Wait for child
                wait(NULL); // Wait for child
            }
            wait(NULL); // Wait for child
        }
        else
            wait(NULL); // Wait for child
        wait(NULL); // Wait for child
    }
    
    return 0;
}