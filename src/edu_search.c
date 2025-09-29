#include "edu_search.h"

#include <stdio.h>
#include <stdlib.h>

#define UNIMPLEMENTED \
    do { \
        fprintf(stderr, "[ERROR] function %s is unimplemented\n", __func__); \
        abort(); \
    } while (0)

#define UNUSED(x) (void)(x)

size_t edu_linear_search(const void *ptr, size_t count, size_t size, const void *key, edu_cmp cmp) {
    UNUSED(ptr);
    UNUSED(count);
    UNUSED(size);
    UNUSED(key);
    UNUSED(cmp);
    UNIMPLEMENTED;
    return 0;
}

size_t edu_binary_search(const void *ptr, size_t count, size_t size, const void *key, edu_cmp cmp) {
    UNUSED(ptr);
    UNUSED(count);
    UNUSED(size);
    UNUSED(key);
    UNUSED(cmp);
    UNIMPLEMENTED;
    return 0;
}
