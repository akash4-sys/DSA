#include "../../headers.h"

class Prefix2D
{
    vector<vector<int>> pf;
public:
    Prefix2D(vector<vector<int>> &m)
    {
        pf = vector(m.size() + 1, vector<int>(m[0].size() + 1, 0));
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++)
                pf[i + 1][j + 1] = (pf[i + 1][j] ^ pf[i][j + 1] ^ m[i][j]) ^ pf[i][j];
    }

    int sumRegion(int x2, int y2, int x1 = 0, int y1 = 0)
    {
        int above = pf[x2 + 1][y1], left = pf[x1][y2 + 1], topLeft = pf[x1][y1];
        return pf[x2 + 1][y2 + 1] ^ topLeft ^ left ^ above;
    }
};

class Solution
{
public:
    int kthLargestValue(vector<vector<int>> &m, int k)
    {
        Prefix2D pf(m);
        priority_queue<int> pq;
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++)
                pq.push(pf.sumRegion(i, j));
        
        while (k-- > 1)
            pq.pop();
        return pq.top();
    }
};