#include "../../headers.h"

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        
        int ans = 0, curr = INT_MIN;
        for (auto p : v)
            if (p[0] > curr)
                ans++, curr = p[1];
        return ans;
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &v)
    {
        vector<int> dp(v.size(), 1);
        sort(v.begin(), v.end());

        int ans = 1;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < v.size(); j++)
                if (v[i][1] < v[j][0])
                    dp[i] = max(dp[i], dp[j] + 1);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


// Time Complexity - O(NlogN)
// Space Complexity - O(N)

class Solution
{
    int dp[1002];
    int rec(vector<vector<int>> &v, int i)
    {
        if (i == v.size())
            return 0;
        if (dp[i + 1] != -1)
            return dp[i + 1];
        
        int res = rec(v, i + 1);
        if (i != -1) {
            int j = upper_bound(begin(v) + i, end(v), v[i][1], [](int t, const auto &v) {
                return v[0] > t;
            }) - begin(v);
            res = max(res, rec(v, j) + 1);
        }
        return dp[i + 1] = res;
    }

public:
    int findLongestChain(vector<vector<int>> &v)
    {
        memset(dp, -1, sizeof(dp));
        sort(v.begin(), v.end());
        return rec(v, -1);
    }
};