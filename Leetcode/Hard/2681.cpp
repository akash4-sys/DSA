#include "../../headers.h"

class Solution
{
public:
    int sumOfPower(vector<int> &v)
    {
        sort(v.begin(), v.end());
        int mod = 1e9 + 7;
        long long ans = 0, sum = 0;

        for (int x : v)
        {
            long long a = ((sum + x) * x) % mod;
            (a *= x) %= mod;
            (ans += a) %= mod;
            sum = ((sum * 2) + x) % mod;
        }
        return ans;
    }
};