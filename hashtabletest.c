/* 
   hashtabletest.c

   Program for testing the functions written in hashtable

   Daniel Lynch, April 2020 for CS50 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "readlinep.h"


void nameprint(FILE *fp, void *item);
void namedelete(void* item);


/* **************************************** */
int main() 
{
  hashtable_t *ht;

  char *myKey = "Daniel";
  int item = 3;
  

  // create a bag
  ht = hashtable_new(17);
  if (ht == NULL) {
    printf("hashtable not created");
    return 1;
  }
  printf("Hashtable created\n");

  

//insert a key, item into the hashtable 

  hashtable_insert(ht, myKey, &item);

  printf("items inserted into hashtable\n");





  return 0;
}


