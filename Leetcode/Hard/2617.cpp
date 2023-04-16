#include "../../headers.h"

class Solution
{
public:
    int minimumVisitedCells(vector<vector<int>> &v)
    {
        vector<set<int>> r(v.size()), c(v[0].size());
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < v.size(); j++)
            {
                r[j].insert(i);
                c[i].insert(j);
            }
        
        queue<vector<int>> q;
        q.push({0, 0, 1});
        while (!q.empty())
        {
            auto cell = q.front();
            q.pop();
            int i = cell[0], j = cell[1], steps = cell[2];
            if (i == v.size() - 1 && j == v[0].size() - 1)
                return steps;
            
            auto it = c[i].lower_bound(j + 1);
            while (it != c[i].end() && *it <= v[i][j] + j)
            {
                q.push({i, *it, steps + 1});
                r[*it].erase(i);
                c[i].erase(it++);
            }

            it = r[j].lower_bound(i + 1);
            while (it != r[j].end() && *it <= v[i][j] + i)
            {
                q.push({*it, j, steps + 1});
                c[*it].erase(j);
                r[j].erase(it++);
            }
        }
        return -1;
    }
};


// Time Complexity - TLE (Sometimes)
// Space Complexity - O(N^3)

#define vec vector<vector<int>>
class Solution
{
    int dfs(vec &v, vector<vec> &dp, int i, int j, int steps)
    {
        if (i == v.size() - 1 && j == v[0].size() - 1)
            return steps + 1;
        if (dp[i][j][steps] != -1)
            return dp[i][j][steps];

        int res = INT_MAX;
        for (int k = i + 1; k < v.size() && k <= v[i][j] + i; k++)
        {
            int x = dfs(v, dp, k, j, steps + 1);
            res = min(res, x ? x : INT_MAX);
        }
        for (int k = j + 1; k < v[0].size() && k <= v[i][j] + j; k++)
        {
            int x = dfs(v, dp, i, k, steps + 1);
            res = min(res, x ? x : INT_MAX);
        }
        return dp[i][j][steps] = res == INT_MAX ? 0 : res;
    }

public:
    int minimumVisitedCells(vec &v)
    {
        vector dp(v.size() + 1, vector(v[0].size(), vector<int>(1e5, -1)));
        int ans = dfs(v, dp, 0, 0, 0);
        return ans ? ans : -1;
    }
};