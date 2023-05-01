// Name: Jake Tsuchiyama
// Date: 11/9/22
// Title: Lab 8 - Generate Text Input
// Description: This program generates a sample text file, which represents a sequence of page numbers

#include <stdio.h>
#include <stdlib.h> 

#define someNumber 20
#define capNumber 11

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer [sizeof(int)];
    int i;
    fp = fopen("testInput.txt", "w");
    for (i=0; i<someNumber; i++){
        sprintf(buffer, "%d\n", rand()%capNumber);
        fputs(buffer, fp);
    }
    fclose(fp);
    return 0;
}