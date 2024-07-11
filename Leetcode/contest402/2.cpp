#include "../../headers.h"

class Solution
{
public:
    long long countCompleteDayPairs(vector<int> &v)
    {
        long long ans = 0, n = v.size();
        map<int, long long> mp;
        for (int &h : v)
        {
            int c = (24 - (h % 24)) % 24;
            if (mp.count(c))
                ans += mp[c];
            mp[h % 24]++;
        }
        return ans;
    }
};