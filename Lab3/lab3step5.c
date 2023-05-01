// Name: Jake Tsuchiyama
// Date: 10/5/22
// Title: Lab3 - IPC w/ Producer-Consumer Problem
// Description: This program implements producer-consumer message communication using pipes. The user inputs a sentence,
// which is sent to the consumer by the producer. The consumer then prints the message to confirm that the message was correctly sent.

/**************************
*	pipe()
**************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/wait.h> 
#include <string.h>

// main
int main(int argc,char *argv[]){
   int  fds[2];
   char buff[60];
   int count;
   int i;
   pipe(fds);
   
   if (fork()==0){ // Producer
       close(fds[0]);
       printf("This is the producer\n");
       printf("Input a sentence.\n");

       char sentence[60];

       scanf("%s", sentence);
       write(fds[1],sentence,strlen(sentence)); // Writes to fds[1] from sentence

       exit(0);
   }
   else if(fork()==0){ // Consumer
       close(fds[1]);
       printf("This is the consumer\n");
       while((count=read(fds[0],buff,60))>0){ // Reads from fds[0] and prints the buffer
           printf("%s", buff);
           printf("\n");
       }
       exit(0);
    }
   else{     
      close(fds[0]);
      close(fds[1]);
      wait(0);
      wait(0);
   }
return 0;
}