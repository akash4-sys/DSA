#include "../../headers.h"


// iterative
class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &m)
    {
        vector<int> ans;
        for (int k = 0; k < m[0].size(); k++)
        {
            int j = k, y;
            for(int i = 0; i < m.size(); i++)
            {
                y = j + m[i][j];
                if(y < 0 || y >= m[0].size() || m[i][y] != m[i][j])
                {
                    j = -1;
                    break;
                }
                j = y;
            }
            ans.push_back(j);
        }
        return ans;
    }
};


class Solution
{
    int dfs(vector<vector<int>> &m, int i, int j)
    {
        if (i == m.size())
            return j;
        if ((j <= 0 && m[i][j] == -1) || (j == m[0].size() - 1 && m[i][j] == 1))
            return -1;
        if (m[i][j] == 1)
            return m[i][j + 1] == 1 ? dfs(m, i + 1, j + 1) : -1;
        return m[i][j - 1] == -1 ? dfs(m, i + 1, j - 1) : -1;
    }

public:
    vector<int> findBall(vector<vector<int>> &m)
    {
        vector<int> ans;
        for (int j = 0; j < m[0].size(); j++)
            ans.push_back(dfs(m, 0, j));
        return ans;
    }
};