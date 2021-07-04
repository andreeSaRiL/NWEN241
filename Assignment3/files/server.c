/**
 * Source file for Assignment 3
 * Full Name:
 * Student ID:
 *
 * You will need to modify this file to perform Tasks 4-5. See the
 * handout for more details.
 *
 * You may also use this as base code to perform Task 6. See the 
 * handout for more details.
 */


#include <stdio.h>
#include <unistd.h> 
#include <string.h>
#include <stdlib.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 


/**
 * Header file contains macros and user-defined types
 * needed in this program. Open server.h for more
 * details.
 */
#include "server.h"


/**
 * Load CSV database file. The implementation of this
 * function is provided so you do not need to implement
 * this.
 * 
 * @param fn CSV database filename
 * @param m Pointer to movie_t
 * @param mlen Number of elements in m
 * @return 0 if successful, -1 otherwise
 */ 
int db_loadfile(const char *fn, movie_t *m, int mlen);


/**
 * If you are implementing your own functions, declare
 * the function prototypes below. Document your function
 * prototypes using the format above in the prototype
 * declaration of db_loadfile.
 */



/**
 * Main function
 */
int main(void)
{
    int ret, sockfd;
    movie_t movies[CSVDB_RECORDS];
    struct sockaddr_in address; 
    
    printf("Starting server...\n");
    
    /* Load CSV database file */
    ret = db_loadfile(CSVDB_FILENAME, movies, CSVDB_RECORDS);
    if(ret) {
        printf("Error: Failed to open %s\n", CSVDB_FILENAME);
        return 0;
    }
    
    /**
     * Write your code below to implement Task 4
     */


    /**
     * Write your code below to implement Task 5
     */     
    

    return 0;
}

/**
 * Implementation of db_loadfile function
 */
int db_loadfile(const char *fn, movie_t *movies, int mlen)
{
    // Input file stream to read csv
    FILE *csv = fopen("scifi.csv", "r");
    if(!csv) {
        return -1;
    }

    // Read csv file line by line and scan for input
    int i = 0;
    while(!feof(csv) && i < mlen) {
	    fscanf(csv, "%[^,],%[^,],%d,%d,%[^\n]%*c", 
	    movies[i].title, movies[i].director, &movies[i].year, 
	    &movies[i].oscars_won, movies[i].origin_country);
        i++;
    }

    // Close file after reading
    fclose(csv);
    
    return 0;
}

/**
 * If you are implementing your own functions, write
 * the function implementation below.
 */

