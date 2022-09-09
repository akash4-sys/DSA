#include "../../headers.h"

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &v)
    {
        int minSum = v[0], maxSum = v[0], cmax = 0, cmin = 0, tot = 0;
        for (int n : v)
        {
            cmax = max(cmax + n, n);
            maxSum = max(maxSum, cmax);
            cmin = min(cmin + n, n);
            minSum = min(minSum, cmin);
            tot += n;
        }
        return maxSum > 0 ? max(maxSum, tot - minSum) : maxSum;
    }
};