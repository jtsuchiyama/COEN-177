// Name: Jake Tsuchiyama
// Date: 11/9/22
// Title: Lab 8 - Memory Management w/ LRU page replacement
// Description: This program simulates the LRU page replacement algorithm given a set of randomly generated page numbers

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

typedef struct {//to 
    int pageno;
    int last_access;
} ref_page;


int main(int argc, char *argv[]){
	int CACHE_SIZE = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[CACHE_SIZE]; // Cache that stores pages
    char pageCache[100]; // Cache that holds the input from test file

    int i;
    int totalFaults = 0; // keeps track of the total page faults
    int totalChecks = 0; // keeps track of the number of page checks
    int totalRequests = 0;
    
    for (i = 0; i < CACHE_SIZE; i++){//initialise cache array  
        cache[i].pageno = -1;
        cache[i].last_access = -1;
    }

    while (fgets(pageCache, 100, stdin)){ // Iterates through all characters in the file
        totalRequests++;
        
    	int page_num = atoi(pageCache); // Stores number read from file as an int

        // Page replacement algorithm
    	bool foundInCache = false;
        for (i=0; i<CACHE_SIZE; i++){ // Search if page is in cache
            if (cache[i].pageno == page_num){
                foundInCache = true;
                cache[i].last_access = totalChecks;
                break; //break out loop because found page_num in cache  
            }
        }   
        if (foundInCache == false){ // Page not in cache -> Page fault -> Add to cache
            printf("%d\n", page_num);
            totalFaults++;

            int minAccess = 2147483647; // Initialize as the max value to search for the smallest
            int minIndex;
            for (i=0; i<CACHE_SIZE; i++){ // Search for last accessed page
                if (cache[i].last_access < minAccess){
                    minAccess = cache[i].last_access;
                    minIndex = i;
                }
            }      
            cache[minIndex].pageno = page_num;
            cache[minIndex].last_access = totalChecks;
        }
        totalChecks++;
    }

    float hitRate = ((float)(totalRequests - totalFaults)/ (float)totalRequests);
    printf("%d Total Requests\n", totalRequests);
    printf("%d Total Page Faults\n", totalFaults);
    printf("%f Hit Rate\n", hitRate);
    return 0;
}
