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
                pf[i + 1][j + 1] = (pf[i + 1][j] + pf[i][j + 1] + m[i][j]) - pf[i][j];
    }

    int sum(int x1, int y1, int x2, int y2) {
        int above = pf[x2 + 1][y1], left = pf[x1][y2 + 1], topLeft = pf[x1][y1];
        return pf[x2 + 1][y2 + 1] + topLeft - left - above;
    }
};

class Solution
{
    int n, m;
    int rec(Prefix2D &v, int k, int cnt, int i, int j)
    {
        if (cnt == 0)
            return 0;
        if (k == 3 || i > n || j > m)
            return 1000;
        
        int res = 1000;
        for (int x = i; x < n; x++)
            for (int y = j; y < m; y++)
            {
                int one = v.sum(i, j, x, y);
                int nxti = y != m - 1 ? i : x + 1;
                int nxtj = y != m - 1 ? y + 1 : 0;
                int area = (x - i + 1) * (y - j + 1);
                res = min(res, rec(v, k + 1, cnt - one, nxti, nxtj) + area);
            }
        
        for (int x = i; x < n; x++)
            for (int y = j + 1; y < m; y++)
                res = min(res, rec(v, k, cnt, x, y));
        return res;
    }

public:
    int minimumSum(vector<vector<int>>& v)
    {
        n = v.size(), m = v[0].size();
        Prefix2D mat(v);
        return rec(mat, 0, mat.sum(0, 0, n - 1, m - 1), 0, 0);
    }
};