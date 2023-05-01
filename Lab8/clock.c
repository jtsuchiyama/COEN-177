// Name: Jake Tsuchiyama
// Date: 11/9/22
// Title: Lab 8 - Memory Management w/ clock page replacement
// Description: This program simulates the clock page replacement algorithm given a set of randomly generated page numbers

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

typedef struct {//to 
    int pageno;
    int chance;
} ref_page;


int main(int argc, char *argv[]){
	int CACHE_SIZE = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[CACHE_SIZE]; // Cache that stores pages
    char pageCache[100]; // Cache that holds the input from test file

    int i;
    int totalFaults = 0; // keeps track of the total page faults
    int totalRequests = 0;
    int counter = 0;
    
    for (i = 0; i < CACHE_SIZE; i++){//initialise cache array  
        cache[i].pageno = -1;
        cache[i].chance = 0;
    }

    while (fgets(pageCache, 100, stdin)){ // Iterates through all characters in the file
        totalRequests++;
        
    	int page_num = atoi(pageCache); // Stores number read from file as an int

        // Page replacement algorithm
    	bool foundInCache = false;
        for (i=0; i<CACHE_SIZE; i++){ // Search if page is in cache
            if (cache[i].pageno == page_num){
                foundInCache = true;
                cache[i].chance = 1;
                break; //break out loop because found page_num in cache  
            }
        }   
        if (foundInCache == false){ // Page not in cache -> Page fault -> Add to cache
            printf("%d\n", page_num);
            totalFaults++;

            for (i=counter; i<CACHE_SIZE; i++){ // Search for last accessed page
                if (cache[i].chance == 0){ // If chance is zero, then replace
                    cache[i].pageno = page_num; // replace minIndex
                    cache[i].chance = 1;
                    
                    counter++;
                    if(counter == CACHE_SIZE) { // Circular queue functionality
                        counter = 0;
                    }
                    break;
                }

                else { // Else, then set chance to 0 and continue
                    cache[i].chance = 0;
                    counter++;
                    if(counter == CACHE_SIZE) { // Circular queue functionality
                        i = -1;
                        counter = 0;
                    }
                }
            }    

            
        }
    }

    float hitRate = ((float)(totalRequests - totalFaults)/ (float)totalRequests);
    printf("%d Total Requests\n", totalRequests);
    printf("%d Total Page Faults\n", totalFaults);
    printf("%f Hit Rate\n", hitRate);
    return 0;
}
