/*#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>*/

// TODO: include define guards to avoid multiple inclusion
//#include "../deps/ckremm/src/tables/tables.h"

#include "jcc.h"

// TODO: replace with Hash Table:
typedef struct Props {
    char id[ID_MAX];
    void *self;
    struct Props *next;
} Props;

struct Object {
    const void *prototype; // object-related base functionality
    Props *properties; // should be a hash table later on
};

// Object Base function declarations
void *Object_constructor(t_pool *pool, void *_self, va_list *args);
void *Object_destructor(t_pool *pool, void *_self);
void *Object_clone(t_pool *pool, void *_self);
