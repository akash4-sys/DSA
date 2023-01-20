#include "headers.h"

class Solution
{
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &qr)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (auto q : qr)
            for (int i = q[0]; i <= q[2]; i++)
            {
                ans[i][q[1]]++;     // mark the beginning column of square
                if (q[3] + 1 < n)
                    ans[i][q[3] + 1]--;         // out of square
            }

        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                ans[i][j] += ans[i][j - 1];
        return ans;
    }
};


// TLE
class Solution
{
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &qr)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (auto q : qr)
        {
            for (int i = q[0]; i <= q[2]; i++)
                for (int j = q[1]; j <= q[3]; j++)
                    ans[i][j]++;
        }
        return ans;
    }
};