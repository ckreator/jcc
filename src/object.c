// Source file for Objects. Object will be the Base type (not Prototype)

#include "jcc.h"
#include "object.h"

//extern const void *Object;

void *Object_constructor(t_pool *pool, void *_self, va_list *args) {
    struct Object *self = _self;

    return self;
}

void *Object_destructor(t_pool *pool, void *_self) {
    struct Object *self = _self;
    // TODO: free all properties
    return self;
}

void *Object_clone(t_pool *pool, void *_self) {
    return NULL;
}

const Prototype _Object = {
    sizeof(struct Object),
    Object_constructor,
    Object_destructor,
    Object_clone,
    NULL
};

const void *Object = &_Object;
