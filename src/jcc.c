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
    void * p = t_pool_alloc(pool, sizeof(prototype->size)); //calloc(1, prototype —> size);
    assert(p);
    * (const Prototype **) p = prototype;
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
        self = (*cp)->destructor(pool, self);
    }
    printf("cp: %p | self: %p\n", cp, self);
    show_t_mem(pool);
    t_pool_dealloc(pool, &self);
    printf("finished jcc_delete\n");
}

/*int main() {

    return 0;
}*/
