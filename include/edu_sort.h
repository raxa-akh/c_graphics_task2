#pragma once

#include <stddef.h>

#include "edu_cmp.h"

/**
 * @brief bubble sort
 * @param ptr   Pointer to the first element of the contiguous array to sort.
 * @param count Number of elements in the array.
 * @param size  Size (in bytes) of a single element.
 * @param cmp   Comparison function compatible with qsort: returns <0, 0, >0
 *              when *(const T*)a is less than / equal to / greater than *(const T*)b.
 */
void edu_bubble_sort(void *ptr, size_t count, size_t size, edu_cmp cmp);

/**
 * @brief selection sort
 * @param ptr   Pointer to the first element of the contiguous array to sort.
 * @param count Number of elements in the array.
 * @param size  Size (in bytes) of a single element.
 * @param cmp   Comparison function compatible with qsort: returns <0, 0, >0
 *              when *(const T*)a is less than / equal to / greater than *(const T*)b.
 */
void edu_selection_sort(void *ptr, size_t count, size_t size, edu_cmp cmp);

/**
 * @brief insertion sort
 * @param ptr   Pointer to the first element of the contiguous array to sort.
 * @param count Number of elements in the array.
 * @param size  Size (in bytes) of a single element.
 * @param cmp   Comparison function compatible with qsort: returns <0, 0, >0
 *              when *(const T*)a is less than / equal to / greater than *(const T*)b.
 */
void edu_insertion_sort(void *ptr, size_t count, size_t size, edu_cmp cmp);

/**
 * @brief shell sort
 * @param ptr   Pointer to the first element of the contiguous array to sort.
 * @param count Number of elements in the array.
 * @param size  Size (in bytes) of a single element.
 * @param cmp   Comparison function compatible with qsort: returns <0, 0, >0
 *              when *(const T*)a is less than / equal to / greater than *(const T*)b.
 */
void edu_shell_sort(void *ptr, size_t count, size_t size, edu_cmp cmp);

/**
 * @brief quick sort
 * @param ptr   Pointer to the first element of the contiguous array to sort.
 * @param count Number of elements in the array.
 * @param size  Size (in bytes) of a single element.
 * @param cmp   Comparison function compatible with qsort: returns <0, 0, >0
 *              when *(const T*)a is less than / equal to / greater than *(const T*)b.
 */
void edu_quick_sort(void *ptr, size_t count, size_t size, edu_cmp cmp);

/**
 * @brief heap sort
 * @param ptr   Pointer to the first element of the contiguous array to sort.
 * @param count Number of elements in the array.
 * @param size  Size (in bytes) of a single element.
 * @param cmp   Comparison function compatible with qsort: returns <0, 0, >0
 *              when *(const T*)a is less than / equal to / greater than *(const T*)b.
 */
void edu_heap_sort(void *ptr, size_t count, size_t size, edu_cmp cmp);

/**
 * @brief Counting sort for integer types only (signed/unsigned 32-bit/64-bit).
 *        Stable order is not required for this assignment.
 *        Values are assumed to fit into a reasonable range for counting.
 *        The @p order parameter controls ascending/descending output.
 * @param ptr   Pointer to the first element of the contiguous array to sort.
 * @param count Number of elements in the array.
 * @param size  Size (in bytes) of a single element.
 * @param order Order of sort
 */
typedef enum {
    EDU_COUNTING_SORT_DESC = 0,
    EDU_COUNTING_SORT_ASC = 1,
} edu_counting_sort_order_e;

void edu_counting_sort(void *ptr, size_t count, size_t size, edu_counting_sort_order_e order);

