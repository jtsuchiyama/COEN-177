// Name: Jake Tsuchiyama
// Date: 10/5/22
// Title: Lab3 - IPC w/ Pipes
// Description: This program creates two child processes, one which sends info down to the child,
// and another that sends info up to the parent.

/**************************
*	pipe()
**************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/wait.h> 
//main
int main() {
 	int fds[2]; // fds[0] = read, fds[1] = write
 	pipe(fds); // Creates a pipe for interprocess communication

	/*child 1 duplicates downstream into stdin, sending info down to child */
	if (fork() == 0) {
		dup2(fds[0], 0); // Redirection downstream
		close(fds[1]);
		execlp("more", "more", 0); // Run more
	}
	/*child 2 duplicates upstream into stdout, sending info up to parent */
	else if (fork() == 0) {
		dup2(fds[1], 1); // Redirection upstream
		close(fds[0]);
		execlp("ls", "ls", 0); // Run ls
	}
	else {  /*parent closes both ends and wait for children*/
		close(fds[0]);
		close(fds[1]);
		wait(0);
		wait(0); 
	}
} 
