// Source file for generic Object Management Functionality
/*#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>*/

// include the needed tools for memory pooling
//#include "../deps/ckremm/src/tables/tables.h"

//#include "object.h"
//#include "prototype.h"
#include "jcc.h"

//extern const void *Object;

void *jcc_new(t_pool *pool, const void * _prototype, ...) {
    const Prototype * prototype = _prototype;
    void * p = t_pool_alloc(pool, prototype->size); //calloc(1, prototype —> size);
    assert(p);
    * (const Prototype **) p = prototype;
    //printf("prototype->size: %lu | prototype->_proto: %p\n", prototype->size, prototype->_proto);
    if (prototype->constructor) {
        va_list ap;
        va_start(ap, _prototype);
        p = prototype->constructor(pool, p, &ap);
        va_end(ap);
    }
    return p;
}

void jcc_delete(t_pool *pool, void *self) {
    const Prototype **cp = self;

    if (self != NULL && *cp != NULL && (*cp)->destructor) {
        //printf("DELETE: cp->size: %lu | cp->_proto: %p\n", (*cp)->size, (*cp)->_proto);
        self = (*cp)->destructor(pool, self);
    }
    //printf("cp: %p | self: %p\n", cp, self);
    //show_t_mem(pool);
    t_pool_dealloc(pool, &self);
    //printf("finished jcc_delete\n");
}

void *jcc_clone(t_pool *pool, void *self) {
    // basically just copy the entry in memory (pool)
    const Prototype **cp = self;

    if (self && *cp && (*cp)->clone) {
        self = (*cp)->clone(pool, self);
        //printf("cp->size: %lu | cp->_proto: %p\n", (*cp)->size, (*cp)->_proto);
        Prototype *copy = t_pool_alloc(pool, (*cp)->size);
        //t_copy_mem(copy, self);
        return copy;
    }
    return NULL;
}

void *jcc_add_property(t_pool *pool, void *self, char *key, void *val, size_t size) {
    // TODO: change this when hash table will be used
    const Prototype **cp = self;

    if (self && *cp && (*cp)->clone) {
        self = (*cp)->add_property(pool, self, key, val, size);
        return self;
    }
    return NULL;
}
