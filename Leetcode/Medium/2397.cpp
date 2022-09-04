#include "headers.h"

class Solution
{
    int m, n, ans = 0;
    vector<int> vis;
    void solve(vector<vector<int>> &mat, int cols, int idx)
    {
        if (!cols || idx == n)
        {
            int currans = 0;
            for (int i = 0; i < m; i++)
            {
                int inc = 1;
                for (int j = 0; j < n; j++)
                    if (mat[i][j] && !vis[j])
                    {
                        inc = 0;
                        break;
                    }
                currans += inc;
            }
            ans = max(ans, currans);
            return;
        }

        vis[idx] = 1;
        solve(mat, cols - 1, idx + 1);
        vis[idx] = 0;
        solve(mat, cols, idx + 1);
        return;
    }

public:
    int maximumRows(vector<vector<int>> &mat, int cols)
    {
        m = mat.size();
        n = mat[0].size();
        vis = vector<int>(n, 0);
        solve(mat, cols, 0);
        return ans;
    }
};