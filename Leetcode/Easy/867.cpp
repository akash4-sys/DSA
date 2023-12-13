#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &m)
    {
        vector t(m[0].size(), vector<int>(m.size(), 0));
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++)
                t[j][i] = m[i][j];
        return t;
    }
};