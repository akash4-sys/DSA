#include "headers.h"

class Solution
{
public:
    int maxCount(vector<int> &v, int n, int m)
    {
        unordered_map<int, int> mp;
        for (int x : v)
            mp[x] = 1;
        
        int sum = 0, ans = 0;
        for (int i = 1; i <= n; i++)
            if (!mp.count(i) && sum + i <= m)
                sum += i, ans++;
        return ans;
    }
};