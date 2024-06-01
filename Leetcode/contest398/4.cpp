#include "../../headers.h"

class Solution
{
public:
    int waysToReachStair(int k)
    {
        if (k == 1 || k == 2)
            return 4;
        if (!k || k == 4)
            return 2;

        int n = 1, val = 1;
        while (val < k)
            val <<= 1, n++;
        if (val - n > k)
            return 0;

        vector<vector<int>> ncr(n + 1);
        for (int i = 0; i <= n; i++) {
            ncr[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; j++)
                ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
        }
        return ncr[n][val - k];
    }
};