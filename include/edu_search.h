#pragma once

#include <stddef.h>

#include "edu_cmp.h"

/**
 * @brief Linear search in an arbitrary (not necessarily sorted) array.
 *
 * Scans the array from left to right and returns the index of the first element
 * that compares equal to the @p key according to @p cmp.
 *
 * @param ptr   Pointer to the first element of the contiguous array to search.
 * @param count Number of elements in the array.
 * @param size  Size (in bytes) of a single element.
 * @param key   Pointer to the value we are searching for.
 * @param cmp   Comparison function compatible with qsort: returns <0, 0, >0
 *              when *(const T*)a is less than / equal to / greater than *(const T*)b.
 *
 * @return Index in range [0, count) if found; otherwise returns @p count.
 */
size_t edu_linear_search(const void *ptr, size_t count, size_t size, const void *key, edu_cmp cmp);

/**
 * @brief Binary search in a sorted (non-decreasing) array.
 *
 * Finds the position of @p key using binary search; the input array must be sorted
 * according to @p cmp (non-decreasing order).
 *
 * @param ptr   Pointer to the first element of the contiguous array to search.
 * @param count Number of elements in the array.
 * @param size  Size (in bytes) of a single element.
 * @param key   Pointer to the value we are searching for.
 * @param cmp   Comparison function compatible with qsort: returns <0, 0, >0
 *              when *(const T*)a is less than / equal to / greater than *(const T*)b.
 *
 * @return Index in range [0, count) if found; otherwise returns @p count.
 */
size_t edu_binary_search(const void *ptr, size_t count, size_t size, const void *key, edu_cmp cmp);
