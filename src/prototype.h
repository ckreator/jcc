#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>




#define ID_MAX 64

// include the needed tools for memory pooling
#include "../deps/ckremm/src/tables/tables.h"

// use a hash_table with linked lists as entries for _prototype chain
// Reasons:
// 1. Easier to remove and add properties
// 2. The Program uses "shadowing" of properties

// kvp - Key-Value Pair
typedef struct kvp {
    char key[ID_MAX];
    void *val;
} kvp;

typedef struct Property {
    struct Property *nxt;
    kvp *entry;
} Property;

typedef struct Prototype {
    size_t size;
    void * (*constructor) (t_pool *pool, void *self, va_list *args);
    void * (*destructor) (t_pool *pool, void *self);
    void * (*clone) (t_pool *pool, void *self);
    void * (*set_property) (t_pool *pool, void *self, char *key, void *val, size_t size);
    void * (*get_property) (t_pool *pool, void *_self, char *key);
    Property *_proto;
} Prototype;

#endif /* PROTOTYPE_H */
