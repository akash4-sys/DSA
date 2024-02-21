#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &m)
    {
        vector<vector<int>> v = m;
        for (int j = 0; j < m[0].size(); j++)
        {
            int x = 0;
            for (int i = 0; i < m.size(); i++)
                x = max(x, m[i][j]);
            for (int i = 0; i < m.size(); i++)
                if (v[i][j] == -1)
                    v[i][j] = x;
        }
        return v;
    }
};