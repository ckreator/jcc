#include <stdio.h>
#include <stdlib.h>

// use a linked list for _prototype chain
// Reasons:
// 1. Easier to remove and add properties
// 2. The Program uses "shadowing" of properties

typedef struct Object {
    unsigned int _len;
    void *(*_prototype);
} Object;

void stuff(int a) {
    printf("Running stuff with %d\n", a);
}

typedef void *(*func)(int a);

int main() {
    Object *test = malloc(sizeof(Object));
    test->_len = 3;
    test->_prototype = malloc(sizeof(void *) * 3);
    int i = 10;
    test->_prototype[0] = (void *) &i;
    int *x = (int *)test->_prototype[0];
    test->_prototype[1] = stuff;
    printf("_prototype => %p | %p | %i\n", test->_prototype[0], &i, *x);
    func s = test->_prototype[1];
    s(15);
    return 0;
}
