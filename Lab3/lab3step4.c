// Name: Jake Tsuchiyama
// Date: 10/5/22
// Title: Lab3 - IPC w/ Pipes: Implementing "cat /etc/passwd | grep root"
// Description: This program computes the result of the command "cat /etc/passwd | grep root"

/**************************
*	pipe()
**************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/wait.h> 

// main
int main(){
   int fds[2];
   pipe(fds);
   
   if (fork()==0) { // Process B downstream
       dup2(fds[0], 0);
       close(fds[1]);
       execlp("grep", "grep", "root", 0); // Run grep
       exit(0);
   }
   else if(fork()==0) { // Process C upstream
       dup2(fds[1], 1);
       close(fds[0]);
       execlp("cat", "cat", "/etc/passwd", 0); // Run cat
       exit(0);
    }
   else{ // Process A
      close(fds[0]);
      close(fds[1]);
      wait(0);
      wait(0);
   }
return 0;
}
