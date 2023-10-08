#include "../../headers.h"

class Solution
{
public:
    int maxDotProduct(vector<int> &a, vector<int> &b)
    {
        int amx = INT_MIN, amn = INT_MAX, bmx = INT_MIN, bmn = INT_MAX;
        for (int n : a)
            amx = max(amx, n), amn = min(amn, n);
        for (int n : b)
            bmx = max(bmx, n), bmn = min(bmn, n);
        
        int ans = max({amn * bmn, amn * bmx, amx * bmn});
        if (ans < 0)
            return ans;
        
        vector dp(a.size() + 1, vector<int>(b.size() + 1, 0));
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < b.size(); j++)
                dp[i + 1][j + 1] = max({dp[i][j] + (a[i] * b[j]), dp[i + 1][j], dp[i][j + 1]});
        return dp[a.size()][b.size()];
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution
{
    int dp[501][501];
    int rec(vector<int> &a, vector<int> &b, int i, int j)
    {
        if (i == a.size() || j == b.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int take = rec(a, b, i + 1, j + 1) + (a[i] * b[j]);
        return dp[i][j] = max({take, rec(a, b, i + 1, j), rec(a, b, i, j + 1)});
    }

public:
    int maxDotProduct(vector<int> &a, vector<int> &b)
    {
        int amx = INT_MIN, amn = INT_MAX, bmx = INT_MIN, bmn = INT_MAX;
        for (int n : a)
            amx = max(amx, n), amn = min(amn, n);
        for (int n : b)
            bmx = max(bmx, n), bmn = min(bmn, n);
        
        memset(dp, -1, sizeof(dp));
        int ans = max({amn * bmn, amn * bmx, amx * bmn});
        return ans < 0 ? ans : rec(a, b, 0, 0);
    }
};