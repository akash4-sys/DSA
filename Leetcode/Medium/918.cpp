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

// TLE
class Solution 
{
public:
    int maxSubarraySumCircular(vector<int>& v)
    {
        int n = v.size(), ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int maxSum = v[i], sum = 0, f = 1;
            for (int j = i; (j % n) != i || f; j++, f = 0)
            {
                maxSum = max(maxSum, sum + v[j % n]);
                sum = max(sum + v[j % n], 0);
            }
            ans = max(ans, maxSum);
        }
        return ans;
    }
};