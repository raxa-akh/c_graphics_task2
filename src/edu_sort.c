#include "edu_sort.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define UNIMPLEMENTED \
    do { \
        fprintf(stderr, "[ERROR] function %s is unimplemented\n", __func__); \
        abort(); \
    } while (0)

#define UNUSED(x) (void)(x)

static void edu_swap(void *a, void *b, size_t size) {
    char tmp[size];
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
}

void edu_bubble_sort(void *ptr, size_t count, size_t size, edu_cmp cmp) {
    int swapped = 1;

    while (swapped) {
        swapped = 0;
        for (size_t i = 0; i < count - 1; ++i) {
            void *val1 = (char *) ptr + i * size;
            void *val2 = (char *) ptr + (i + 1) * size;
            if (cmp(val1, val2) > 0) {
                edu_swap(val1, val2, size);
                swapped = 1;
            }
        }
        --count;
    }
}

void edu_selection_sort(void *ptr, size_t count, size_t size, edu_cmp cmp) {
    UNUSED(ptr);
    UNUSED(count);
    UNUSED(size);
    UNUSED(cmp);
    UNIMPLEMENTED;
}

void edu_insertion_sort(void *ptr, size_t count, size_t size, edu_cmp cmp) {
    UNUSED(ptr);
    UNUSED(count);
    UNUSED(size);
    UNUSED(cmp);
    UNIMPLEMENTED;
}

void edu_shell_sort(void *ptr, size_t count, size_t size, edu_cmp cmp) {
    UNUSED(ptr);
    UNUSED(count);
    UNUSED(size);
    UNUSED(cmp);
    UNIMPLEMENTED;
}

void edu_quick_sort(void *ptr, size_t count, size_t size, edu_cmp cmp) {
    UNUSED(ptr);
    UNUSED(count);
    UNUSED(size);
    UNUSED(cmp);
    UNIMPLEMENTED;
}

void edu_heap_sort(void *ptr, size_t count, size_t size, edu_cmp cmp) {
    UNUSED(ptr);
    UNUSED(count);
    UNUSED(size);
    UNUSED(cmp);
    UNIMPLEMENTED;
}

void edu_counting_sort(void *ptr, size_t count, size_t size, edu_counting_sort_order_e order) {
    UNUSED(ptr);
    UNUSED(count);
    UNUSED(size);
    UNUSED(order);
    UNIMPLEMENTED;
}
