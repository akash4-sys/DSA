#include "../../headers.h"

https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/description/

class Solution
{
public:
    int minOperations(vector<int> &a, vector<int> &b)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < a.size(); i++)
            mp[a[i]] = i;
        
        vector<int> dp(a.size(), 0);
        for (int x : b)
            if (mp.count(x))
                dp[mp[x]] = max(dp[mp[x]], mp[x] ? dp[mp[x] - 1] + 1 : 1);
        return a.size() - *max_element(dp.begin(), dp.end());
    }
};