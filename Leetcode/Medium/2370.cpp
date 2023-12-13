#include "../../headers.h"

// Time Complexity - O(N * 26)
// Space Complexity - O(1)

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int n = s.size(), ans = 0;
        vector<int> dp(26, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int c = s[i] - 'a', l = c - k, r = c + k + 1, cnt = 0;
            dp[c] = max(dp[c], *max_element(dp.begin() + max(l, 0), dp.begin() + min(r, 26)) + 1);
            ans = max(ans, dp[c]);
        }
        return ans;
    }
};


// Time Complexity - O(N * 26)
// Space Complexity - O(N * 26)

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int n = s.size(), ans = 0;
        vector<int> dp(n, 0), id(26, -1);
        for (int i = n - 1; i >= 0; i--)
        {
            int c = s[i] - 'a', cnt = 0;
            for (int j = max(c - k, 0); j <= min(c + k, 25); j++)
                if (id[j] != -1)
                    cnt = max(cnt, dp[id[j]]);
            dp[i] = max(dp[i], cnt + 1);
            id[c] = i;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
    int dp[100001];
    int rec(string &s, int k, int i)
    {
        if (i == s.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        
        int res = 0;
        for (int j = i + 1; j < s.size(); j++)
            if (abs(s[i] - s[j]) <= k)
                res = max(res, rec(s, k, j) + 1);
        return dp[i] = res;
    }

public:
    int longestIdealString(string s, int k)
    {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
            ans = max(ans, rec(s, k, i) + 1);
        return ans;
    }
};