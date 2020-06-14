
Hashtable 

WTF is Hashing?

 Hashing is a quick-and-dirty way to assign items to different ‘mailboxes’. If you think of a mailroom with thousands of pigeon holes to put graded tests back into, this is much like a hash function. Some hash functions operate at random- selecting mailboxes randomly- there might already be tests in that mailbox, but it will add another one. The average amount of tests in each mailbox is called the load factor. The number of mailboxes is usually determined up front- so once a number is chosen, and orders of magnitude higher number of items are assigned, load factor will be high and performance will be poor. 

Hashtable

 These mailboxes are “setPointers” in my hashtable program. The actual contents that reside within the mailboxes are sets, as defined in another file. The sets store [key, item] pairs. The functions for Hashtable.c are as follows:



Create a new hashtable and allocates memory. 
hashtable_t *hashtable_new(const int num_slots);
 Insert item, identified by key (string), into the given hashtable.
bool hashtable_insert(hashtable_t *ht, const char *key, void *item);
Return the item associated with the given key.
void *hashtable_find(hashtable_t *ht, const char *key);
Print the whole table; provide the output file and func to print each item.
void hashtable_print(hashtable_t *ht, FILE *fp, void (*itemprint)(FILE *fp, const char *key, void *item));
Iterate over all items in the table; in undefined order.
void hashtable_iterate(hashtable_t *ht, void *arg, void (*itemfunc)(void *arg, const char *key, void *item) );
Delete hashtable, calling a delete function on each item.
void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item) );

Implementation 

The Hashtable function was unique in that it pulled in other methods from the given file package from the lab. The first header pulled was the JHash.h, where a function called JenkinsHash which returns hash(str) % mod. Each of the items stored in these numbers of pointers are sets, so some set operations were used. 

Assumptions

No NULL values can be added- so you’ll need to have complete information for whatever you’re adding, unlike the scholastic database in our first lab which had many NULL values. Naturally at least 1 pointer address will need to be created. 

Compilation

Needs to have access to set.c/set.h and jash.c/jhash.h either in the same directory with a MAKE file or a master MAKE file can be written at the parent directory to compile all of the files. 


