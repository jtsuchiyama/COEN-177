// Name: Jake Tsuchiyama
// Date: 11/16/22
// Title: Lab 9 - File Performance: Reading and Writing Files w/ Varied Size Buffer
// Description: This program simulates the reading and writing of files to a buffer of a varied size

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char buffer[atoi(argv[2])]; 
    FILE *fp;
    FILE *fp_out;
    fp = fopen(argv[1], "rb"); 
    fp_out = fopen("out.txt", "wb");
    while (fread(buffer, sizeof(buffer), 1, fp)){
        fwrite(buffer, sizeof(buffer), 1, fp_out);
    }
    fclose(fp);
    fclose(fp_out);
}
