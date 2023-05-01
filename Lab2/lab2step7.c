// Name: Jake Tsuchiyama
// Date: 9/28/22
// Title: Lab 2 - Step 7
// Description: This program demonstrates the ability of processes to call commands.

/*Sample C program for Lab assignment 1*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pid_t  pid;
    printf("\n Before forking.\n");
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }    
    // Child process
    else if(pid == 0) {
        execlp("/bin/ls", "ls", NULL);
    }
    // Parent process, wait until child is complete
    else {
        wait(NULL);
        printf("Child Complete\n");
        exit(0);
    }
    return 0;
}