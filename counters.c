/*
Counters.c

Written by Daniel Lynch 4/24/2020
A 2nd-year MBA student at the Tuck School of Business at Dartmouth


This file will have the 'guts' of the various functions surrounding counters

*/
// include the header file for set, and other things we will need 

#include "counters.h"
//io & standard libray 
#include <stdio.h>
#include <stdlib.h>
//strings & booleans
#include <string.h>
#include <stdbool.h>


//enumerate all of the elements that will be part of this data structure

// NOTE: the formatting of this file was copied and pasted from 
//bac.c, which was provided code - the functions were copied from 
//the header file (necessary to say this?)

/**************** local types ****************/

typedef struct localCounters{
     //have pointer to the next 
    struct localCounters *next;
    //each set holds counts and keys, both defined as integers
    int key;
    int count;
} localCounters_t;

/**************** global types ****************/

typedef struct counters{
    struct localCounters *head;
} counters_t;  // opaque to users of the module

/****************local functions ****************/

//have new function for local counters
//take a key, no need for count because it will be 0 initially
static localCounters_t *localCounters_new(int key){
    //allocate memory for the new counters 
    localCounters_t *localCounters = malloc(sizeof(localCounters_t));
    if (localCounters==NULL){
        return NULL;
    } else {
        localCounters->key=key; //getting a warning on this, what the fuck 
        //initialize all counts to 0 
        localCounters->count = 0;
        return localCounters;
        
    }

}
/**************** global functions ****************/

//let's get this party started 

//create new counters set. returns a reference (pointer)
//to a new counterset, returns NULL if error 
counters_t *counters_new(void){
    //allocate memory for the new counters 
    counters_t *counters = malloc(sizeof(counters_t));
    if (counters!=NULL){
        counters->head = NULL;
        return counters;
    } else {
        return NULL;
   }

}

int counters_add(counters_t *ctrs, const int key){
    //valid pointer to counterset, and key(must be >= 0)
    if ( ctrs!=NULL && key>=0){
        //if the key does not exist yet, make it, set count to 1
        if (counters_get(ctrs, key)==0){
            localCounters_t *counterNew = localCounters_new(key);
            counterNew->count = 1;
            if (counterNew!=NULL){
                counterNew->next = ctrs->head;
                ctrs->head = counterNew;
            }
        } 
         //if key exists, increment count
         else {
             for (localCounters_t *localCounters = ctrs->head; localCounters!=NULL; localCounters = localCounters->next){
                 if (localCounters->key ==key){
                     localCounters->count = (localCounters->count +1);
                 }
             }
         }
    }
    return 0;
}

//return the count for a given key
int counters_get(counters_t *ctrs, const int key){
    //same as counters_add- need valid pointer and key 
    if ( ctrs!=NULL && key>=0){
        //find the given key by iterating through counters
        for (localCounters_t *localCounters = ctrs->head; localCounters!=NULL; localCounters = localCounters->next){
            if (localCounters->key == key){
                return localCounters->count;
            }
        }
    }
    //return 0 if key not found or is NULL
    return 0;
}

//function that sets the current count for a key 

bool counters_set(counters_t *ctrs, const int key, const int count){
    //key(must be >= 0), 
    //counter value(must be >= 0).
    if (key >=0 && ctrs!=NULL && count>=0){
        //iterate through the counters to find our given key 
         for (localCounters_t *localCounters = ctrs->head; localCounters!=NULL; localCounters = localCounters->next){
            if (localCounters->key == key){
                 //update count to the given value from the parameter
                localCounters->count = count;
                return true;
            }
         }    
           //if it makes it to this point the key DNE and we'll make a new one
           counters_add(ctrs,key);
           counters_set(ctrs,key,count);
           return false;
    }

return 0;
}

//Print all counters; provide the output file.

void counters_print(counters_t *ctrs, FILE *fp){
        //make sure set exists
if (fp!=NULL) {
    if (ctrs!=NULL){
        //start the list with an open bracket for readability
        fputc('{', fp);
        //iterate through the set 
        for (localCounters_t *localCounters = ctrs->head; localCounters!=NULL; localCounters = localCounters->next){
            fprintf(fp, "%d:%d", localCounters->key, localCounters->count);
                //throw a comma between each of the pairs
                fputc(',', fp);
            }
        }
        fputc('}', fp);  
    } 
    else{
        fputs("NULL SET\n", fp);
        }
}

//function for iterating over all the counters and performing a function given

void counters_iterate
(counters_t *ctrs, void *arg, void (*itemfunc)(void *arg, const int key, const int count)){
    if (  itemfunc!=NULL && ctrs!=NULL   ){
        //use same for loop we've been using
        for (localCounters_t *localCounters = ctrs->head; localCounters!=NULL; localCounters = localCounters->next){
            (*itemfunc)(arg, localCounters->key, localCounters->count);
        }
    //no return statements, just do nothing if paramters are NULL
     }
}



//function for deleting counters
void counters_delete(counters_t *ctrs){
     for (localCounters_t *localCounters = ctrs->head; localCounters!=NULL;){
         localCounters_t *nextCounter = localCounters->next;
         free(localCounters);
         //move to the next one to 'free' it 
         localCounters = nextCounter;
     }
     //free memory used for paramter
     free(ctrs);
}