#include "../../headers.h"

class Solution
{
public:
    int maxSelectedElements(vector<int> &v)
    {
        int ans = 0;
        unordered_map<int, int> dp;
        sort(v.begin(), v.end());
        for (int a : v)
            ans = max({ans, dp[a + 1] = dp[a] + 1, dp[a] = dp[a - 1] + 1});
        return ans;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    int dp[1000001][2];
    map<int, int> mp;

    int rec(int a, int c)
    {
        if (dp[a][c] != -1)
            return dp[a][c];
        
        int res = 0;
        if (mp[a] > c)
            return dp[a][c] = rec(a + 1, 0) + 1;
        if (mp.count(a + 1))
            return dp[a][c] = rec(a + 1, 1) + 1;
        return 0;
    }

public:
    int maxSelectedElements(vector<int> &v)
    {
        for (int a : v)
            mp[a]++;
        
        sort(v.begin(), v.end());
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int a : v)
            ans = max({ans, rec(a, 1) + 1, rec(a + 1, 0) + 1});
        return ans;
    }
};