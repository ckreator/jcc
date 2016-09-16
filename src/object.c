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

void *Object_set_property(t_pool *pool, void *_self, char *key, void *val, size_t size) {
    struct Object *self = _self;
    //self->
    self->properties = t_pool_alloc(pool, sizeof(Props));
    // get length of identifier
    int length = 0;
    char *p = key;
    for (; *p != '\0'; p++, length++) ;
    // allocate enough memory for string
    self->properties->id = t_pool_alloc(pool, sizeof(char) * length + 1);
    // copy identifier
    int i;
    for (i = 0; *key != '\0'; i++, key++)
        self->properties->id[i] = *key;

    self->properties->id[i] = '\0';
    //table_m *dest = __get_section(pool, size);

    char *tmp = t_pool_alloc(pool, size);//dest->ptr;
    char *src = val;
    self->properties->self = tmp;
    // copy the memory to the pool

    for (i = 0; i < size; i++, src++)
        tmp[i] = *src;

    //printf("done copying => %i\n", *(int *)self->properties->self);

    self->properties->next = NULL;
    return _self;
}

void *Object_get_property(t_pool *pool, void *_self, char *key) {
    struct Object *self = _self;
    Props *search = self->properties;
    for (; search != NULL; search = search->next) {
        //compare the strings
        bool found = false;
        //printf("getting object prop: key: %s | id: %s\n", key, search->id);
        int i = 0;
        for (; search->id[i] == key[i] && key[i] != '\0' && search->id[i] != '\0'; i++) {
            //printf("i: %i | id[i]: %c | key[i]: %c\n", i, search->id[i], key[i]);
        }
        if (key[i] == '\0' && key[i] == search->id[i])
            return search->self;
    }
    return NULL;
}

const Prototype _Object = {
    sizeof(struct Object),
    Object_constructor,
    Object_destructor,
    Object_clone,
    Object_set_property,
    Object_get_property,
    NULL
};

const void *Object = &_Object;
