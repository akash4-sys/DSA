#include "../../headers.h"

class Solution
{
public:
    int minimumCoins(vector<int> &v)
    {
        int n = v.size();
        vector<int> dp(n + 1, 0);
        deque<int> q;
        for (int i = 0; i < n; i++)
        {
            while (!q.empty() && q.front() * 2 + 2 < i + 1)
                q.pop_front();
            while (!q.empty() && dp[q.back()] + v[q.back()] >= dp[i] + v[i])
                q.pop_back();
            q.push_back(i);
            dp[i + 1] = dp[q.front()] + v[q.front()];
        }
        return dp[n];
    }
};


class Solution
{
public:
    int minimumCoins(vector<int> &v)
    {
        int n = v.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int res = INT_MAX;
            for (int j = i + 1; j <= min(n, i * 2 + 2); j++)
                res = min(res, dp[j]);
            dp[i] = res +  v[i];
        }
        return dp[0];
    }
};


class Solution
{
    int dp[1001][1001];
    int rec(vector<int> &v, int i, int k)
    {
        if (i == v.size())
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        
        int ans = k ? rec(v, i + 1, k - 1) : INT_MAX;
        return dp[i][k] = min(ans, rec(v, i + 1, i + 1) + v[i]);
    }

public:
    int minimumCoins(vector<int> &v)
    {
        memset(dp, -1, sizeof(dp));
        return rec(v, 0, 0);
    }
};