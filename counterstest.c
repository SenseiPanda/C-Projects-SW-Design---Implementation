/* 
   counterstest.c

   Program for testing the functions written in counters

   Daniel Lynch, April 2020 for CS50 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counters.h"
#include "readlinep.h"

int main() 
{
  counters_t *ct = counters_new();

  

  // create a bag
  
  if (ct == NULL) {
    printf("counters not created");
    return 1;
  }
  printf("counters created\n");

  int ten = 10;
   counters_add(ct, ten);

   

//insert a key, item into the hashtable 

  

  printf("key added to counters\n");


  return 0;
}
