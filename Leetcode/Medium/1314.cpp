#include "../../headers.h"

// Formula based

class Solution
{
    int m, n;
    int check(int i, int j, vector<vector<int>> &sum)
    {
        if (i < 0 || j < 0)
            return 0;
        if (i >= m)
            i = m - 1;
        if (j >= n)
            j = n - 1;
        return sum[i][j];
    }

public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0)), sum = ans;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                sum[i][j] = mat[i][j] + check(i - 1, j, sum) + check(i, j - 1, sum) - check(i - 1, j - 1, sum);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans[i][j] = check(i + k, j + k, sum) - check(i + k, j - k - 1, sum) - check(i - k - 1, j + k, sum) + check(i - k - 1, j - k - 1, sum);
        return ans;
    }
};