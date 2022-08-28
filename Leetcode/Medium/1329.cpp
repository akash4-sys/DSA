#include "../../headers.h"

class Solution
{
public:
    void compute(vector<vector<int>> &m, int x, int y)
    {
        vector<int> v;
        int i = x, k = y, l = 0;
        while (i < m.size() && k < m[0].size())
            v.push_back(m[i++][k++]);

        sort(v.begin(), v.end());
        i = x, k = y;
        while (i < m.size() && k < m[0].size())
            m[i++][k++] = v[l++];
    }

    vector<vector<int>> diagonalSort(vector<vector<int>> &m)
    {
        for (int j = 0; j < m[0].size(); j++)
            compute(m, 0, j);
        for (int i = 1; i < m.size(); i++)
            compute(m, i, 0);
        
        return m;
    }
};