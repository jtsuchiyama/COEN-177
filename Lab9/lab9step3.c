// Name: Jake Tsuchiyama
// Date: 11/16/22
// Title: Lab 9 - File Performance: Reading Files w/ Varied Size Buffer
// Description: This program simulates the reading of files to a buffer of a varied size

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char buffer[atoi(argv[2])]; 
    FILE *fp;
    fp = fopen(argv[1], "rb"); 
    while (fread(buffer, sizeof(buffer), 1, fp)){
    }
    fclose(fp);
}
