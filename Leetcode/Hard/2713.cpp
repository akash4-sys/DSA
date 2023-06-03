#include "headers.h"

class Solution
{
public:
    int maxIncreasingCells(vector<vector<int>> &grid)
    {
        int m = size(grid), n = size(grid[0]);
        vector<vector<int>> dp(m, vector<int>(n, 0));
        map<int, vector<int>> mp;
        vector<int> ans(n + m, 0);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                mp[grid[i][j]].push_back((i * n) + j);

        for (auto &[x, pos] : mp)
        {
            for (int p : pos)
            {
                int i = p / n, j = p % n;
                dp[i][j] = max(ans[i], ans[j + m]) + 1;
            }

            for (int p : pos)
            {
                int i = p / n, j = p % n;
                ans[j + m] = max(ans[j + m], dp[i][j]);
                ans[i] = max(ans[i], dp[i][j]);
            }
        }
        return *max_element(ans.begin(), ans.end());
    }
};


//  Time Complexity - O(NMlogN)
// Space Complexity - O(N^2) + auxiliary stack + passbyvaluemap

#define vv vector<vector<int>>
#define mp map<int, vector<int>>

class Solution
{
    int ans, n, m;
    vv dp;

    int rec(vv &grid, mp row[], mp col[], int i, int j)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int res = 1;
        auto c = row[i].lower_bound(grid[i][j] + 1);
        if (c != row[i].end())
            for (auto x : (*c).second)
                res = max(res, rec(grid, row, col, i, x) + 1);
            
        auto r = col[j].lower_bound(grid[i][j] + 1);
        if (r != col[j].end())
            for (auto x : (*r).second)
                res = max(res, rec(grid, row, col, x, j) + 1);
        return dp[i][j] = res;
    }

public:
    int maxIncreasingCells(vv &grid)
    {
        ans = 0, m = size(grid), n = size(grid[0]);
        dp = vv(m, vector<int>(n, -1));
        mp row[m], col[n];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                row[i][grid[i][j]].push_back(j);
                col[j][grid[i][j]].push_back(i);
            }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, rec(grid, row, col, i, j));
        return ans;
    }
};