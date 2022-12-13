#include "../../headers.h"

#define vv vector<vector<int>>
#define vec vector<int>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& m) 
    {
        for(int i = 1; i < m.size(); i++)
            for(int j = 0; j < m.size(); j++)
                    m[i][j] += min({m[i - 1][max(j - 1, 0)], m[i - 1][j], m[i - 1][min(j + 1, (int)m.size() - 1)]});
        return *min_element(m.back().begin(), m.back().end());
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N^2) + auxiliary stack space
class Solution
{
    int dfs(vv &grid, vv &dp, int i, int j)
    {
        if(i == grid.size() - 1)
            return grid[i][j];

        if(dp[i][j] != INT_MAX)
            return dp[i][j];

        for(auto y : {-1, 0, 1})
            if(j + y >= 0 && j + y < grid.size())
                dp[i][j] = min(dp[i][j], grid[i][j] + dfs(grid, dp, i + 1, j + y));
        return dp[i][j];
    }

public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        vv dp(grid.size() + 1, vec(grid.size() + 1, INT_MAX));
        int ans = INT_MAX;
        for (int i = 0; i < grid.size(); i++)
            ans = min(ans, dfs(grid, dp, 0, i));
            
        return ans;
    }
};


// @lc app=leetcode id=931 lang=cpp