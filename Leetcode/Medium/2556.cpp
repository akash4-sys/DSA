#include "../../headers.h"

class Solution
{
    int dfs(vector<vector<int>> &m, int i, int j)
    {
        if (i >= m.size() || j >= m[0].size() || !m[i][j])
            return 0;
        m[i][j] = 0;
        int x = dfs(m, i + 1, j) || dfs(m, i, j + 1);
        return (i == m.size() - 1 && j == m[0].size() - 1) || x;
    }

public:
    bool isPossibleToCutPath(vector<vector<int>> &m)
    {
        if (!dfs(m, 0, 0))
            return 1;
        m[0][0] = 1;
        m.back().back() = 1;
        if (!dfs(m, 0, 0))
            return 1;
        return 0;
    }
};


class Solution
{
    bool diagonal(vector<vector<int>> &m, int x, int y)
    {
        int curr = 0, a = 0;
        for (int i = x, j = y; i < m.size() && j < m[0].size(); i++, j++)
            curr += m[i][j], a++;
        return curr == a;
    }

public:
    bool isPossibleToCutPath(vector<vector<int>> &m)
    {
        int c = 0;
        for (int it = 0; it < m.size(); it++)
            c += diagonal(m, it, 0);
        for (int it = 1; it < m[0].size(); it++)
            c += diagonal(m, 0, it);
        c -= m.back()[0] + m[0].back();
        return c < 2;
    }
};