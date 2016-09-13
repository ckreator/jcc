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
    return _self;
}

void *Object_add_property(t_pool *pool, void *_self, char *key, void *val, size_t size) {
    struct Object *self = _self;
    //self->
    self->properties = t_pool_alloc(pool, sizeof(Props));
    int i;
    for (i = 0; *key != '\0'; key++)
        self->properties->id[i] = *key;

    self->properties->id[i] = '\0';
    //table_m *dest = __get_section(pool, size);

    char *tmp = t_pool_alloc(pool, size);//dest->ptr;
    char *src = val;
    self->properties->self = tmp;
    // copy the memory to the pool

    for (i = 0; i < size; i++, src++)
        tmp[i] = *src;

    self->properties->next = NULL;
    return _self;
}

const Prototype _Object = {
    sizeof(struct Object),
    Object_constructor,
    Object_destructor,
    Object_clone,
    Object_add_property,
    NULL
};

const void *Object = &_Object;
