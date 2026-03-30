/*
 * sumEvenAfterQueries
 *
 * For each query [val, idx]: adds val to nums[idx], then records
 * the running sum of all even elements in nums.
 *
 * Time:  O(n + q)  — one pass for init, one pass per query
 * Space: O(q)      — result array only
 *
 * Returns a heap-allocated array of size queriesSize (caller must free),
 * or NULL on invalid input / allocation failure.
 */

#include <stdlib.h>
#include <stddef.h>

static inline int is_even(int x) { return (x & 1) == 0; }

int *sumEvenAfterQueries(
        int       *nums,
        int        numsSize,
        int      **queries,
        int        queriesSize,
        const int *queriesColSize,
        int       *returnSize)
{
    /* --- guard against bad arguments --- */
    *returnSize = 0;
    if (!nums || numsSize <= 0 || !queries || queriesSize <= 0
            || !queriesColSize || !returnSize) {
        return NULL;
    }

    int *result = (int *)malloc((size_t)queriesSize * sizeof(int));
    if (!result) return NULL;

    /* --- initial even-sum --- */
    int even_sum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (is_even(nums[i])) even_sum += nums[i];
    }

    /* --- process queries --- */
    for (int i = 0; i < queriesSize; i++) {
        /* validate that this query row has at least 2 columns */
        if (queriesColSize[i] < 2) {
            free(result);
            *returnSize = 0;
            return NULL;
        }

        const int val = queries[i][0];
        const int idx = queries[i][1];

        /* validate index bounds */
        if (idx < 0 || idx >= numsSize) {
            free(result);
            *returnSize = 0;
            return NULL;
        }

        /* remove old contribution if even */
        if (is_even(nums[idx])) even_sum -= nums[idx];

        /* apply update */
        nums[idx] += val;

        /* add new contribution if even */
        if (is_even(nums[idx])) even_sum += nums[idx];

        result[i] = even_sum;
    }

    *returnSize = queriesSize;
    return result;
}