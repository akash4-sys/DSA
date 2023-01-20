#include "../../headers.h"

// Kadane's Algorithm

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = INT_MIN, sum = 0;
        for (int n : nums)
        {
            maxSum = max(maxSum, sum + n);
            sum = max(sum + n, 0);
        }
        return maxSum;
    }
};