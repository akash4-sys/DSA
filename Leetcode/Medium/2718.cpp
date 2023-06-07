#include "headers.h"

class Solution
{
public:
    long long matrixSumQueries(int n, vector<vector<int>> &q)
    {
        vector<int> row(n, 1), col(n, 1);
        long long r = n, c = n, ans = 0;
        for (int i = q.size() - 1; i >= 0; i--)
        {
            if (!q[i][0] && row[q[i][1]])
            {
                ans += (c * q[i][2]);
                row[q[i][1]] = 0;
                r--;
            }
            if (q[i][0] && col[q[i][1]])
            {
                ans += (r * q[i][2]);
                col[q[i][1]] = 0;
                c--;
            }
        }
        return ans;
    }
};