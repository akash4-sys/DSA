#include "../../headers.h"

// Kadane's Algorithm

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = 0, sum = 0;
        for (int n : nums)
        {
            maxSum = max(maxSum, sum + n);
            sum = max(sum + n, 0);
        }
        return maxSum;
    }
};