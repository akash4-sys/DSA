#include "../../headers.h"

class Solution
{
    int dfs(vector<int> &v, int k, vector<int> &dp, int i)
    {
        if (i == v.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        vector<int> mp(v.size());
        int ans = INT_MAX, val = 0;
        for (int j = i; j < v.size(); j++)
        {
            if (++mp[v[j]] > 1)
                val += (mp[v[j]] == 2) ? 2 : 1;
            ans = min(ans, k + val + dfs(v, k, dp, j + 1));
        }
        return dp[i] = ans;
    }

    void normalize(vector<int> &v)
    {
        unordered_map<int, int> mp;
        for (int &n : v)
        {
            if (!mp.count(n))
                mp[n] = mp.size();
            n = mp[n];
        }
    }

public:
    int minCost(vector<int> &v, int k)
    {
        vector<int> dp(v.size(), -1);
        normalize(v);
        return dfs(v, k, dp, 0);
    }
};

// Tabulation
// Time Complexity - O(N^2)
// Space Complexity - O(N)
// Accepted

class Solution
{
public:
    int minCost(vector<int> &v, int k)
    {
        vector<int> dp(v.size() + 1, INT_MAX);
        dp[v.size()] = 0;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            unordered_map<int, int> mp;
            for (int j = i, val = 0; j < v.size(); j++)
            {
                if (++mp[v[j]] > 1)
                    val += (mp[v[j]] == 2) ? 2 : 1;
                dp[i] = min(dp[i], k + val + dp[j + 1]);
            }
        }
        return dp[0];
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(N^2)
// Accepted

class Solution
{
    int dfs(vector<vector<int>> &sub, int k, vector<int> &dp, int i)
    {
        if (i == sub.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;
        for (int j = i; j < sub.size(); j++)
            ans = min(ans, k + sub[i][j] + dfs(sub, k, dp, j + 1));
        return dp[i] = ans;
    }

public:
    int minCost(vector<int> &v, int k)
    {
        vector<int> dp(v.size(), -1);
        vector<vector<int>> sub(v.size(), vector<int>(v.size(), 0));
        for (int i = 0; i < v.size(); i++)
        {
            unordered_map<int, int> mp;
            for (int j = i, val = 0; j < v.size(); j++)
            {
                if (++mp[v[j]] > 1)
                    val += (mp[v[j]] == 2) ? 2 : 1;
                sub[i][j] = val;
            }
        }
        return dfs(sub, k, dp, 0);
    }
};

// TLE
class Solution
{
    int dfs(vector<int> &v, int k, vector<int> &dp, int i)
    {
        if (i == v.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        unordered_map<int, int> mp;
        int ans = INT_MAX, val = 0;
        for (int j = i; j < v.size(); j++)
        {
            if (++mp[v[j]] > 1)
                val += (mp[v[j]] == 2) ? 2 : 1;
            ans = min(ans, k + val + dfs(v, k, dp, j + 1));
        }
        return dp[i] = ans;
    }

public:
    int minCost(vector<int> &v, int k)
    {
        vector<int> dp(v.size(), -1);
        return dfs(v, k, dp, 0);
    }
};

// TLE
// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    int minCost(vector<int> &v, int k, int i = 0)
    {
        if (i == v.size())
            return 0;

        unordered_map<int, int> mp;
        int ans = INT_MAX, val = 0;
        for (int j = i; j < v.size(); j++)
        {
            if (++mp[v[j]] > 1)
                val += (mp[v[j]] == 2) ? 2 : 1;
            ans = min(ans, k + val + minCost(v, k, j + 1));
        }
        return ans;
    }
};

// TLE
// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
    int dfs(vector<int> &v, int k, unordered_map<int, int> mp, int i, int val)
    {
        if (i == v.size())
            return val + k;
        if (++mp[v[i]] > 1)
            val += (mp[v[i]] == 2) ? 2 : 1;

        int part = val + k + dfs(v, k, {}, i + 1, 0);
        int dont = dfs(v, k, mp, i + 1, val);
        return min(part, dont);
    }

public:
    int minCost(vector<int> &v, int k)
    {
        return dfs(v, k, {}, 0, 0);
    }
};