#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sequentialDigits(int low, int high, int *returnSize)
{
    *returnSize = 0;
    int *ans = malloc(1);
    int low_first_digit = low;
    int low_num_digits = 1;
    while (low_first_digit > 9)
    {
        low_num_digits++;
        low_first_digit /= 10;
    }
    int res;
    int curr_digit = low_first_digit;
    int curr_length = low_num_digits;

    while (1)
    {
        res = 0;
        if (curr_digit > 10 - curr_length)
        {
            curr_length++;
            curr_digit = 1;
        }
        for (int i = 0; i < curr_length; i++)
        {
            res = res * 10 + curr_digit + i;
        }
        curr_digit++;

        if (res > high)
        {
            return ans;
        }
        if (res < low)
        {
            continue;
        }

        (*returnSize)++;
        ans = realloc(ans, *returnSize * sizeof(int));
        ans[*returnSize - 1] = res;

    }
}


int main(void)
{
    int *size = malloc(sizeof(int));
    int *res = sequentialDigits(8511, 23553, size);
    for (int i = 0; i < *size; i++)
    {
        printf("%d\n", res[i]);
    }
    free(size);
    free(res);
    return 0;
}