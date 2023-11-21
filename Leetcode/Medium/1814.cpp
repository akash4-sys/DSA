#include "../../headers.h"

class Solution
{
public:
    int countNicePairs(vector<int> &v)
    {
        int ans = 0, mod = 1e9 + 7;
        unordered_map<int, int> mp;
        for (int a : v)
        {
            int r = 0;
            for (int b = a; b > 0; b /= 10)
                r = (r * 10) + (b % 10);
            (ans += mp[a - r]++) %= mod;
        }
        return ans;
    }
};