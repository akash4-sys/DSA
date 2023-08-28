#include "headers.h"

class Solution
{
public:
    int maximumBeauty(vector<int> &v, int k)
    {
        map<int, int> mp;
        for (int a : v)
            mp[a - k]++, mp[a + k + 1]--;
        
        int ans = 0, cnt = 0;
        for (auto [n, c] : mp)
            cnt += c, ans = max(ans, cnt);
        return ans;
    }
};