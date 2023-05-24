#include "../../headers.h"

class Solution
{
public:
    int sumOfPower(vector<int> &v)
    {
        sort(v.begin(), v.end());
        int n = v.size(), mod = 1e9 + 7;
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            long long maxk = (2LL << i) % mod;
            long long mink = (2LL << (n - i - 1)) % mod;
            long long x = (maxk * v[i] * v[i]) % mod;
            long long y = (mink * v[i]) % mod;
            (ans += x + y) %= mod;
        }
        return ans;
    }
};