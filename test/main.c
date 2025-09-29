#include "criterion/criterion.h"

#include "edu_sort.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "edu_search.h"

const size_t arr_len = 1000;
const int num_max = 1000;

// TODO: add tests for already sorted and all equals arrs

// helper funcs

static bool edu_is_sorted(const void *ptr, size_t count, size_t size, edu_cmp cmp) {
    const char *arr = ptr;
    for (size_t i = 1; i < count; ++i) {
        const void *val1 = arr + (i - 1) * size;
        const void *val2 = arr + i * size;
        if (cmp(val1, val2) > 0) {
            return false;
        }
    }
    return true;
}

static bool edu_is_sorted_desc(const void *ptr, size_t count, size_t size, edu_cmp cmp) {
    const char *arr = ptr;
    for (size_t i = 1; i < count; ++i) {
        const void *val1 = arr + (i - 1) * size;
        const void *val2 = arr + i * size;
        if (cmp(val1, val2) < 0) {
            return false;
        }
    }
    return true;
}

static int edu_cmp_int(const void *lhs, const void *rhs) {
    const int a = *(const int *) lhs, b = *(const int *) rhs;
    if (a < b) {
        return -1;
    }
    if (a > b) {
        return 1;
    }
    return 0;
}

static int *edu_gen_arr(void) {
    int *arr = malloc(arr_len * sizeof(int));
    if (!arr) {
        return NULL;
    }
    for (size_t i = 0; i < arr_len; ++i) {
        arr[i] = rand() % num_max;
    }
    return arr;
}

static int *edu_gen_sorted_arr(bool nondecreasing) {
    int *arr = edu_gen_arr();
    qsort(arr, arr_len, sizeof(int), edu_cmp_int);
    if (!nondecreasing) {
        for (size_t i = 0; i < arr_len / 2; ++i) {
            const int tmp = arr[i];
            arr[i] = arr[arr_len - 1 - i];
            arr[arr_len - 1 - i] = tmp;
        }
    }
    return arr;
}

static int *edu_gen_equal_arr(int value) {
    int *arr = malloc(arr_len * sizeof(int));
    if (!arr) {
        return NULL;
    }
    for (size_t i = 0; i < arr_len; ++i) {
        arr[i] = value;
    }
    return arr;
}

static void suite_init(void) {
    srand(12345);
}

TestSuite(bubble_sort, .init = suite_init);
TestSuite(selection_sort, .init = suite_init);
TestSuite(insertion_sort, .init = suite_init);
TestSuite(shell_sort, .init = suite_init);
TestSuite(quick_sort, .init = suite_init);
TestSuite(counting_sort, .init = suite_init);

TestSuite(linear_search, .init = suite_init);
TestSuite(binary_search, .init = suite_init);

// sort tests

// bubble sort

Test(bubble_sort, random) {
    int *arr = edu_gen_arr();

    edu_bubble_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(bubble_sort, already_sorted) {
    int *arr = edu_gen_sorted_arr(true);

    edu_bubble_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(bubble_sort, all_equal) {
    int *arr = edu_gen_equal_arr(42);

    edu_bubble_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

// selection sort

Test(selection_sort, random) {
    int *arr = edu_gen_arr();

    edu_selection_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(selection_sort, already_sorted) {
    int *arr = edu_gen_sorted_arr(true);

    edu_selection_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(selection_sort, all_equal) {
    int *arr = edu_gen_equal_arr(42);

    edu_selection_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

// insertion sort

Test(insertion_sort, random) {
    int *arr = edu_gen_arr();

    edu_insertion_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(insertion_sort, already_sorted) {
    int *arr = edu_gen_sorted_arr(true);

    edu_insertion_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(insertion_sort, all_equal) {
    int *arr = edu_gen_equal_arr(42);

    edu_insertion_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

// shell sort

Test(shell_sort, random) {
    int *arr = edu_gen_arr();

    edu_shell_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(shell_sort, already_sorted) {
    int *arr = edu_gen_sorted_arr(true);

    edu_shell_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(shell_sort, all_equal) {
    int *arr = edu_gen_equal_arr(42);

    edu_shell_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

// quick sort

Test(quick_sort, random) {
    int *arr = edu_gen_arr();

    edu_quick_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(quick_sort, already_sorted) {
    int *arr = edu_gen_sorted_arr(true);

    edu_quick_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(quick_sort, all_equal) {
    int *arr = edu_gen_equal_arr(42);

    edu_quick_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

// heap sort

Test(heap_sort, random) {
    int *arr = edu_gen_arr();

    edu_heap_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(heap_sort, already_sorted) {
    int *arr = edu_gen_sorted_arr(true);

    edu_heap_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(heap_sort, all_equal) {
    int *arr = edu_gen_equal_arr(42);

    edu_heap_sort(arr, arr_len, sizeof(int), edu_cmp_int);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

// counting sort

Test(counting_sort, random_asc) {
    int *arr = edu_gen_arr();

    edu_counting_sort(arr, arr_len, sizeof(int), EDU_COUNTING_SORT_ASC);

    cr_assert(edu_is_sorted(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

Test(counting_sort, random_desc) {
    int *arr = edu_gen_arr();

    edu_counting_sort(arr, arr_len, sizeof(int), EDU_COUNTING_SORT_DESC);

    cr_assert(edu_is_sorted_desc(arr, arr_len, sizeof(int), edu_cmp_int));
    free(arr);
}

// search tests

// linear search

Test(linear_search, found) {
    int *arr = edu_gen_arr();

    const int key = arr[rand() % arr_len];

    const size_t pos = edu_linear_search(arr, arr_len, sizeof(int), &key, edu_cmp_int);
    cr_expect(pos < arr_len);
    if (pos < arr_len) {
        cr_assert_eq(arr[pos], key);
    }

    free(arr);
}

Test(linear_search, not_found) {
    int *arr = edu_gen_arr();

    const int key = num_max + 1;

    const size_t pos = edu_linear_search(arr, arr_len, sizeof(int), &key, edu_cmp_int);
    cr_assert_eq(pos, arr_len);

    free(arr);
}

Test(linear_search, empty_arr) {
    int *arr = NULL;

    const int key = 42;

    const size_t pos = edu_linear_search(arr, 0, sizeof(int), &key, edu_cmp_int);
    cr_assert_eq(pos, 0);

    free(arr);
}

// binary search

Test(binary_search, found) {
    int *arr = edu_gen_sorted_arr(true);

    const int key = arr[rand() % arr_len];

    const size_t pos = edu_binary_search(arr, arr_len, sizeof(int), &key, edu_cmp_int);
    cr_expect(pos < arr_len);
    if (pos < arr_len) {
        cr_assert_eq(arr[pos], key);
    }

    free(arr);
}

Test(binary_search, not_found) {
    int *arr = edu_gen_sorted_arr(true);

    const int key = num_max + 1;

    const size_t pos = edu_binary_search(arr, arr_len, sizeof(int), &key, edu_cmp_int);
    cr_assert_eq(pos, arr_len);

    free(arr);
}

Test(binary_search, empty_arr) {
    int *arr = NULL;

    const int key = 42;

    const size_t pos = edu_binary_search(arr, 0, sizeof(int), &key, edu_cmp_int);
    cr_assert_eq(pos, 0);

    free(arr);
}
