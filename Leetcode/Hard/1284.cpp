#include "../../headers.h"

#define v vector<vector<int>>
class Solution
{
    bool zeroMat(v &m, int f = 0)
    {
        for (auto r : m)
            for (int c : r)
                f += c;
        return !f;
    }

    v flip(v &m, int i, int j)
    {
        m[i][j] ^= 1;
        if(i - 1 >= 0) m[i-1][j] ^= 1;
        if(i + 1 < m.size()) m[i+1][j] ^= 1;
        if(j - 1 >= 0) m[i][j-1] ^= 1;
        if(j + 1 < m[0].size()) m[i][j+1] ^= 1;
        return m;
    }

    int recurseFlip(v m, int i, int j)
    {
        if (j == m[0].size())
            i++, j = 0;
        if (i == m.size())
            return zeroMat(m) ? 0 : 10000;
        return min(recurseFlip(m, i, j + 1), recurseFlip(flip(m, i, j), i, j + 1) + 1);
    }

public:
    int minFlips(v &m)
    {
        int ans = recurseFlip(m, 0, 0);
        return ans >= 10000 ? -1 : ans;
    }
};