#include "../../headers.h"

class Solution
{
    int dp[1001][1023] = {0}, mod = 1e9 + 7;
    int getCol(int mask, int i)
    {
        return (mask >> (i * 2)) & 3;
    }

    int setCol(int mask, int pos, int col)
    {
        return mask | (col << (pos * 2));
    }

public:
    int colorTheGrid(int m, int n, int i = 0, int j = 0, int prev = 0, int curr = 0)
    {
        if (i == m)
            return colorTheGrid(m, n, 0, j + 1, curr, 0);
        if (j == n)
            return 1;
        if (!i && dp[j][prev])
            return dp[j][prev];
        
        int ans = 0, up = i ? getCol(curr, i - 1) : 0, left = getCol(prev, i);
        for (int k = 1; k <= 3; k++)
            if (k != up && k != left)
                ans = (ans + colorTheGrid(m, n, i + 1, j, prev, setCol(curr, i, k))) % mod;
        if (!i)
            return dp[j][prev] = ans;
        return ans;
    }
};