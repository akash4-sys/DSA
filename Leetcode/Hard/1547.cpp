#include "../../headers.h"

// Time Complexity - O(N^3)
// Space Complexity - O(N^2)

class Solution
{
public:
    int minCost(int n, vector<int> &v)
    {
        v.push_back(0), v.push_back(n);
        sort(v.begin(), v.end());
        int sz = v.size();
        vector dp(sz, vector<int>(sz, 0));

        for (int i = sz - 1; i >= 0; i--)
            for (int j = 0; j < sz; j++)
            {
                int res = INT_MAX;
                for (int k = i + 1; k < j; k++)
                    res = min(res, dp[i][k] + dp[k][j] + (v[j] - v[i]));
                dp[i][j] = res == INT_MAX ? 0 : res;
            }
        return dp[0][sz - 1];
    }
};


// Time Complexity - O(N^3)
// Space Complexity - O(N^2)

class Solution
{
    int rec(vector<int> &v, vector<vector<int>> &dp, int i, int j)
    {
        if (j < i)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int res = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            int x = rec(v, dp, i, k);
            int y = rec(v, dp, k, j);
            res = min(res, x + y + (v[j] - v[i]));
        }
        return dp[i][j] = res == INT_MAX ? 0 : res;
    }

public:
    int minCost(int n, vector<int> &v)
    {
        v.push_back(0), v.push_back(n);
        sort(v.begin(), v.end());
        vector dp(v.size(), vector<int>(v.size(), -1));
        return rec(v, dp, 0, v.size() - 1);
    }
};


// Time Complexity - O(N^3)
// Space Complexity - O(N^2)

class Solution
{
    int rec(vector<int> &v, vector<vector<int>> &dp, int l, int r, int i, int j)
    {
        if (j < i)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int res = INT_MAX;
        for (int k = i; k <= j; k++)
        {
            int x = rec(v, dp, l, v[k], i, k - 1);
            int y = rec(v, dp, v[k], r, k + 1, j);
            res = min(res, x + y + (r - l));
        }
        return dp[i][j] = res == INT_MAX ? 0 : res;
    }

public:
    int minCost(int n, vector<int> &v)
    {
        sort(v.begin(), v.end());
        vector dp(v.size(), vector<int>(v.size(), -1));
        return rec(v, dp, 0, n, 0, v.size() - 1);
    }
};

// MLE

class Solution
{
    int rec(vector<int> &v, vector<vector<int>> &dp, int l, int r)
    {
        if (dp[l][r] != -1)
            return dp[l][r];

        int res = INT_MAX;
        for (int i = 0; i < v.size(); i++)
            if (v[i] > l && v[i] < r)
            {
                int x = rec(v, dp, l, v[i]);
                int y = rec(v, dp, v[i], r);
                res = min(res, x + y + (r - l));
            }
        return dp[l][r] = res == INT_MAX ? 0 : res;
    }

public:
    int minCost(int n, vector<int> &v)
    {
        vector dp(n + 1, vector<int>(n + 1, -1));
        return rec(v, dp, 0, n);
    }
};