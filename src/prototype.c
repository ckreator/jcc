// Source file for Prototype

#include "prototype.h"


/* Prototype Chain:
 * Object Contains hash table -> _prototype
 * the entry in the hash table is a linked list
 * The first entry in the list with matching identifier is used (shadowing)
 * When Inheriting, the whole chain is inherited
 */

 // API:
 // return a void pointer to a newly create object

//typedef void *(*func)(int a);
//typedef int (*out)();
