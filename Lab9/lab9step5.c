// Name: Jake Tsuchiyama
// Date: 11/16/22
// Title: Lab 9 - File Performance: Reading and Writing Files w/ Varied Size Buffer using Threads
// Description: This program simulates the reading and writing of files to a buffer of a varied size using threads

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Global variables for threads
int buffer_size;

typedef struct {
    int iter;
    char *read_file;
}arg_struct;

void *read_write(void *args) {
    char buffer[buffer_size]; 
    char out_name[20];
    FILE *fp;
    FILE *fp_out;
    
    arg_struct *arg = (arg_struct *)args;
    int iteration = (*arg).iter;
    char *read_name = (*arg).read_file;

    fp = fopen(read_name, "rb"); 
    sprintf(out_name, "out%d.txt", iteration);
    fp_out = fopen(out_name, "wb");

    while (fread(buffer, sizeof(buffer), 1, fp)){
        fwrite(buffer, sizeof(buffer), 1, fp_out);
    }
    fclose(fp);
    fclose(fp_out);
}

int main(int argc, char *argv[]) {
    int i;
    buffer_size = atoi(argv[2]);

    int num_threads = atoi(argv[3]);
    pthread_t threads[num_threads];

    for(i=0; i < num_threads; i++) {
        arg_struct *arg;
        arg = malloc(sizeof(arg_struct));
        (*arg).iter = i;
        (*arg).read_file = argv[1];
        pthread_create(&threads[i], NULL, read_write, (void *)arg);
    }

    for(i=0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}
