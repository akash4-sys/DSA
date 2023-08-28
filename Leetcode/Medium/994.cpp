#include "../../headers.h"

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &v)
    {
        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int m = v.size(), n = v[0].size(), ans = 0, fresh = 0;
        queue<int> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (v[i][j] == 2)
                    q.push((i * 1000) + j);
                fresh += v[i][j] == 1;
            }
        
        for (; !q.empty() && fresh; ans++)
            for (int k = q.size(); k; k--)
            {
                int i = q.front() / 1000, j = q.front() % 1000;
                q.pop();
                for (auto [dx, dy] : dirs)
                {
                    int x = i + dx, y = j + dy;
                    if (x >= 0 && x < m && y >= 0 && y < n && v[x][y] == 1)
                        v[x][y] = 2, q.push((x * 1000) + y), fresh--;
                }
            }
        return fresh ? -1 : ans;
    }
};