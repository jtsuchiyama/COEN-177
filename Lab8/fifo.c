// Name: Jake Tsuchiyama
// Date: 11/9/22
// Title: Lab 8 - Memory Management w/ FIFO page replacement
// Description: This program simulates the FIFO page replacement algorithm given a set of randomly generated page numbers

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

typedef struct {//to 
    int pageno;
} ref_page;


int main(int argc, char *argv[]){
	int CACHE_SIZE = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[CACHE_SIZE]; // Cache that stores pages
    char pageCache[100]; // Cache that holds the input from test file

    int i;
    int totalFaults = 0; // keeps track of the total page faults
    int totalRequests = 0;
    int placeInArray=0;
    
    for (i = 0; i < CACHE_SIZE; i++){//initialise cache array  
        cache[i].pageno = -1;
    }

    while (fgets(pageCache, 100, stdin)){ // Iterates through all characters in the file
        totalRequests++;
        
    	int page_num = atoi(pageCache); // Stores number read from file as an int

        // Page replacement algorithm
    	bool foundInCache = false;
        for (i=0; i<CACHE_SIZE; i++){ // Search if page is in cache
            if (cache[i].pageno == page_num){
                foundInCache = true;
                break; //break out loop because found page_num in cache  
            }
        }   
        if (foundInCache == false){ // Page not in cache -> Page fault -> Add to cache
            printf("%d\n", page_num);
            cache[placeInArray].pageno = page_num;
            totalFaults++;
            placeInArray++; //Need to keep the value within the cacheSize
            if(placeInArray == CACHE_SIZE) // Reset to beginning of array
                placeInArray = 0;
        }
    }

    float hitRate = ((float)(totalRequests - totalFaults)/ (float)totalRequests);
    printf("%d Total Requests\n", totalRequests);
    printf("%d Total Page Faults\n", totalFaults);
    printf("%f Hit Rate\n", hitRate);
    return 0;
}
