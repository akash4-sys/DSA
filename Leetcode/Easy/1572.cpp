#include "../../headers.h"

class Solution
{
public:
    int diagonalSum(vector<vector<int>> &m)
    {
        int ans = 0, n = m.size();
        for (int i = 0; i < n; i++)
            ans += m[i][i] + m[i][n - i - 1];
        return ans - (n % 2 ? m[n / 2][n / 2] : 0);   
    }
};