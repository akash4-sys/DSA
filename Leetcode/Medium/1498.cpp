#include "../../headers.h"

class Solution
{
    long long mod = 1e9 + 7;
    long long power(long long a, long long b)
    {
        long long res = 1;
        for (a %= mod; b > 0; b >>= 1)
        {
            if (b & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
        }
        return res;
    }

public:
    int numSubseq(vector<int> &v, int t)
    {
        int ans = 0, n = v.size();
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            if (v[i] > t)
                break;
            int j = upper_bound(v.begin() + i, v.end(), t - v[i]) - v.begin();
            long long x = j - i - 1;
            if (x >= 0)
                ans = (ans + power(2, x)) % mod;
        }
        return ans;
    }
};