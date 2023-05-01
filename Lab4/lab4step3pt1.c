// Name: Jake Tsuchiyama
// Date: 10/12/22
// Title: Lab 4 - Matrix transposition with threads w/o synchronization
// Description: This program uses threads to copy and update a matrix in parallel w/o synchronization.

#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

#define N 100
#define M 100

double matrixA[N][M], matrixB[N][M];

// Prints values of matrix
void matPrint(double matrix[M][N]) {
    int i, j;
    for(i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            printf("%g ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Print complete.\n");
}

// Copies values from matrixA to matrixB
void *matCopy() {
    int i, j;
    for(i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            matrixB[i][j] = matrixA[i][j];
        }
    }
    printf("Copy complete.\n");
}

// Doubles values in matrix
void *matDouble() {
    int i, j;
    for(i=0;i<N;i++) {
        for(j=0;j<M;j++) {
            matrixA[i][j] = matrixA[i][j] * 2;
        }
    }
    printf("Doubling complete.\n");
}

int main() {
    // Variable intialization
    int i, j;
    int x = 0;
    pthread_t thread1, thread2;

    // Populate matrixA and matrixB with values
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            matrixA[i][j] = x++;
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            matrixB[i][j] = 0;
    
    matPrint(matrixA);

    pthread_create(&thread1, NULL, matCopy, NULL); 
    pthread_create(&thread2, NULL, matDouble, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    matPrint(matrixA);
}