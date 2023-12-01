#include "../../headers.h"

class Solution
{
public:
    long long maximumSum(vector<int> &v)
    {
        long long ans = 0, n = v.size();
        for (int i = 1; i <= n; i++)
        {
            long long sum = 0;
            for (int j = 1; j * j * i <= n; j++)
                sum += v[(j * j * i) - 1];
            ans = max(ans, sum);
        }
        return ans;
    }
};