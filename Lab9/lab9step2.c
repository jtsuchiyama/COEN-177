// Name: Jake Tsuchiyama
// Date: 11/16/22
// Title: Lab 9 - File Performance: Reading Files w/ Fixed Size Buffer
// Description: This program simulates the reading of files to a buffer of a fixed size

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char buffer[10000]; 
    FILE *fp;
    fp = fopen(argv[1], "rb"); 
    while (fread(buffer, sizeof(buffer), 1, fp)){
    }
    fclose(fp);
}
