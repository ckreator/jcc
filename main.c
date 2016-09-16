// Main entry point for JCC - JavaScript Constructs in C
//#include "deps/ckremm/src/tables/tables.h"
//#include "src/object.h"
#include "src/object.h"
extern const void *Object;

int main() {
    int i = 11;
    t_pool *pool = create_pool(256);
    void *obj = jcc_new(pool, Object);
    void *copy = jcc_clone(pool, obj);
    show_t_mem(pool);

    jcc_set_property(pool, obj, "first", &i, sizeof(int));
    //jcc_delete(pool, obj);
    int *got = jcc_get_property(pool, obj, "first");
    printf("got: %p\n", got);
    printf("got: %i\n", *got);
    *got += 19;
    int *check = jcc_get_property(pool, obj, "first");
    printf("check: %i | got: %i\n", *check, *got);

    int ary[] = {9, 15, 934, 2223};
    printf("sizeof ary => %lu\n", sizeof(ary));

    void *ary_obj = jcc_new(pool, Object);
    jcc_set_property(pool, ary_obj, "nums", ary, sizeof(ary));

    int *nu_ary = jcc_get_property(pool, ary_obj, "nums");
    for (int a = 0; a < 4; a++)
        printf("nu_ary: %i\n", nu_ary[a]);

    //char str[] = "hello there!";
    //printf("sizeof str => %lu\n", sizeof(str));

    //char *p = str;
    //printf("sizeof p => %lu\n", sizeof(p));

    show_t_mem(pool);
    destroy_t_pool(pool);
    return 0;
}
