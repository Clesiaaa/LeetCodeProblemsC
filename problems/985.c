#include <stdlib.h>

int* sumEvenAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    (void)queriesColSize; // suppress unused warning

    int evenSum = 0;
    *returnSize = queriesSize;

    int* result = (int*)malloc(sizeof(int) * queriesSize);
    if (!result) return NULL; // safety check

    // Initial sum of even numbers
    for (int i = 0; i < numsSize; i++) {
        if ((nums[i] & 1) == 0) {  // faster even check
            evenSum += nums[i];
        }
    }

    for (int i = 0; i < queriesSize; i++) {
        int val = queries[i][0];
        int idx = queries[i][1];

        int oldVal = nums[idx];

        // If old value was even, remove it
        if ((oldVal & 1) == 0) {
            evenSum -= oldVal;
        }

        // Update value
        nums[idx] += val;

        int newVal = nums[idx];

        // If new value is even, add it
        if ((newVal & 1) == 0) {
            evenSum += newVal;
        }

        result[i] = evenSum;
    }

    return result;
}