#include "../../headers.h"

class Solution
{
public:
    long long minCost(vector<int> &a, vector<int> &b)
    {
        long long d = 0, ans = 0; 
        map<int, long long> mp;
        for (int i = 0; i < a.size(); i++)
            mp[a[i]]++, mp[b[i]]--;
        
        for (auto &[n, c]: mp)
        {
            if (c % 2)
                return -1;
            d += max(0LL, c / 2);
        }

        for (auto &[n, c]: mp)
        {
            long long swaps = min(d, abs(c) / 2);
            ans += swaps * min(n, mp.begin()->first * 2);
            d -= swaps;
        }
        return ans;
    }
};