#include "../../headers.h"

class Solution
{
public:
    long long maximumSumOfHeights(vector<int> &v)
    {
        long long ans = 0, n = v.size();
        for (int i = 0; i < n; i++)
        {
            long long sum = 0;
            for (int j = i, mn = INT_MAX; j >= 0; j--)
                mn = min(mn, v[j]), sum += mn;
            
            if (i != n - 1)
                for (int j = i + 1, mn = v[j]; j < n; j++)
                    mn = min(mn, v[j]), sum += mn;
            ans = max(ans, sum);
        }
        return ans;
    }
};