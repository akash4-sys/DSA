#include "../../headers.h"

class Solution
{
    int dirs[9][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 0}};
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &v)
    {
        int m = v.size(), n = v[0].size();
        vector ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int sum = 0, cnt = 0;
                for (auto &d : dirs)
                {
                    int x = i + d[0], y = j + d[1];
                    if (x >= 0 && x < m && y >= 0 && y < n)
                        sum += v[x][y], cnt++;
                }
                ans[i][j] = sum / cnt;
            }
        return ans;
    }
};