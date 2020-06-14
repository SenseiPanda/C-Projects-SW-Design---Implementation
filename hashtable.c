/* 
A program for writing functions and structure for the hashtable data type.
A hashtable is like a hashmap in java, array of addressess to counters/sets/etc (although hashmap can hold many diff. data types)
Written  by Daniel Lynch 4/24/2020
*/
#include "hashtable.h"
#include <stdio.h>
#include "jhash.h"
#include <stdbool.h>
#include "../set/set.h"
#include <stdlib.h>
#include <string.h>

typedef struct hashtable{
    int num_slots;
    //set of pointers
    set_t   **setPointers;
} hashtable_t;

hashtable_t *hashtable_new(const int num_slots){
    //number of slots to be used for the hashtable (must be > 0)
    if ( num_slots>0 ){
        hashtable_t *hashtable = malloc( sizeof( hashtable_t ) );
        //the module is responsible for allocating memory for a copy of the key string
        //use set data type for size of memory allocation
        hashtable->setPointers = calloc( num_slots , sizeof ( set_t* ) );
        //set num_slots to the # of num_slots in new hastable
        hashtable->num_slots = num_slots;
        return hashtable;
            } else{
                //return NULL if error
                return NULL;
            }

}


/**************** hashtable_insert ****************/
/* Insert item, identified by key (string), into the given hashtable.
 *
 * Caller provides:
 *   valid pointer to hashtable, valid string for key, valid pointer for item.
 * We return:
 *   false if key exists in ht, any parameter is NULL, or error;
 *   true if new item was inserted.
 * Notes:
 *   The key string is copied for use by the hashtable; that is, the module
 *   is responsible for allocating memory for a copy of the key string, and
 *   later deallocating that memory; thus, the caller is free to re-use or 
 *   deallocate its key string after this call.  
 */
bool hashtable_insert(hashtable_t *ht, const char *key, void *item){
    //The key string is copied for use by the hashtable
    char *copyOfKey = malloc(strlen(key)+1);
    //assign copy to current value
    strcpy(copyOfKey, key);
    //are all the parameters there? if not, fuck it 
    if (ht == NULL || key == NULL || item == NULL){
        return false;
    } else {
        if ( hashtable_find(ht, copyOfKey) == NULL ){
            int ptr = JenkinsHash(key, ht->num_slots);
            if ( set_insert(ht->setPointers[ptr], key, item)== true){
                return true;
            } 

        }

    }
    return 0;
   
}
/**************** hashtable_find ****************/
/* Return the item associated with the given key.
 *
 * Caller provides:
 *   valid pointer to hashtable, valid string for key.
 * We return:
 *   pointer to the item corresponding to the given key, if found;
 *   NULL if hashtable is NULL, key is NULL, or key is not found.
 * Notes:
 *   the hashtable is unchanged by this operation.
 */

void *hashtable_find(hashtable_t *ht, const char *key){
    if ( ht == NULL || key == NULL ){
        return NULL;
    } else {
        //use jhash to find pointer in hashtable 
        int ptr = JenkinsHash(key, ht->num_slots); 
        //TA tip: treat keys like set and use set_find- is boolean, so it can return!
        return set_find(ht->setPointers[ptr], key);
        } 
    }




void hashtable_print(hashtable_t *ht, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item)){
    if ( fp != NULL && ht != NULL ) {
        for ( int i=0; i < ht->num_slots; i++){
            //output the set to the file, one set on each new line 
            fprintf(fp, "SetPointer %d , ", i);
            //TA tip: use set_print to print  all of the iems in the set
            set_print(ht->setPointers[i], fp, (*itemprint));
        } 

    } else {
            if ( fp != NULL ){
                fputs( "null\n", fp );
            }
            
        }
}


void hashtable_iterate(hashtable_t *ht, void *arg, void (*itemfunc)(void *arg, const char *key, void *item)){
    if ( ht == NULL || itemfunc == NULL ){
        return;
} else {
    //first iterate over each of the setPointers in the hashtable, 
    //then the sets themselves using set_iterate 
    for ( int i=0; i < ht->num_slots; i++ ){
        set_iterate( ht->setPointers[i] , arg, (*itemfunc) );
    }
}
}


void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item) ){
    if ( ht != NULL){
        //do the same thing we've been doing for iteration, but perform delete using set function
        for ( int i=0; i < ht->num_slots; i++ ){
            set_delete(ht->setPointers[i] , (*itemdelete) );
        }
        free( ht->setPointers );

        free( ht );
    }
}