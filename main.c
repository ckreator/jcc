// Main entry point for JCC - JavaScript Constructs in C
//#include "deps/ckremm/src/tables/tables.h"
//#include "src/object.h"
#include "src/object.h"
extern const void *Object;

int main() {
    int i = 11;
    t_pool *pool = create_pool(64);
    void *obj = jcc_new(pool, Object);
    jcc_delete(pool, obj);

    show_t_mem(pool);
    destroy_t_pool(pool);
    return 0;
}
