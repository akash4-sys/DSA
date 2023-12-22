#include "../../headers.h"

class Solution
{
public:
    int countPairs(vector<int> &v)
    {
        unordered_map<int, long long> mp;
        for (int &n : v)
            mp[n]++;
        
        long long ans = 0, mod = 1e9 + 7, x;
        for (auto &[n, c] : mp)
            for (int i = 0; i < 32; i++)
                if (x = (1LL << i) - n; x >= n && mp.count(x))
                {
                    if (x == n)
                        (ans += (c * (c - 1) / 2LL)) %= mod;
                    else
                        (ans += (mp[x] * c)) %= mod;
                }
        return ans;
    }
};