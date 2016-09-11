// Header file for Prototype-based Object Management
#include "prototype.h"
//#include "../deps/ckremm/src/tables/tables.h"
// Generic function definitions
/*********************************************************
 * Description: creates a new Object that implements the 'prototype' interface
 * Example. For type 'String', invoke this way:
 *
 * void *str = jcc_new(some_pool, String, "hello there");
 *********************************************************/
void *jcc_new(t_pool *pool, const void * _prototype, ...);

/*********************************************************
 * Description: deletes an object and frees the memory in the pool
 * Example. For type 'String', invoke this way:
 *
 * jcc_delete(some_pool, str);
 *********************************************************/
void jcc_delete(t_pool *pool, void *self);
