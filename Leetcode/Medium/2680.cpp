#include "../../headers.h"

class Solution
{
public:
    long long maximumOr(vector<int> &v, int k)
    {
        long long n = v.size(), pf = 0, ans = 0;
        k = 1 << k;

        vector<long long> sf(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
            sf[i] = sf[i + 1] | v[i];
        
        for (int i = 0; i < n; i++)
        {
            long long x = (long long)v[i] * k;
            long long sum = x | pf | sf[i + 1];
            ans = max(ans, sum);
            pf |= v[i];
        }
        return ans;
    }
};