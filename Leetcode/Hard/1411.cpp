#include "../../headers.h"

class Solution
{
public:
    int numOfWays(int n)
    {
        long long twoCol = 6, threeCol = 6, nxt2Col, nxt3Col, mod = 1e9 + 7;
        for (; n > 1; n--)
        {
            nxt2Col = twoCol * 3 + threeCol * 2;
            nxt3Col = twoCol * 2 + threeCol * 2;
            twoCol = nxt2Col % mod;
            threeCol = nxt3Col % mod;
        }
        return (twoCol + threeCol) % mod;
    }
};


// Time Complexity - O(N)
// Space Complexity - O(N*2)
// numOfCols means number of colors in a particular row where 0 -> 2colors, 1 -> 3colors
class Solution
{
    int dp[5001][2] = {0}, mod = 1e9 + 7;
    int recurse(int n, int numOfCols)
    {
        if (n == 1)
            return 1;
        if (dp[n][numOfCols] != 0)
            return dp[n][numOfCols];
        long long ans = (recurse(n - 1, numOfCols) * 2LL + recurse(n - 1, numOfCols ^ 1) * 2LL) % mod;
        ans = !numOfCols ? (ans + recurse(n - 1, numOfCols)) % mod : ans;
        return dp[n][numOfCols] = ans;
    }

public:
    int numOfWays(int n)
    {
        return (recurse(n, 0) * 6LL + recurse(n, 1) * 6LL) % mod;
    }
};

// Time Complexity - O(N * 27 ^ 2)
class Solution
{
    int dp[5001][4][4][4] = {0}, mod = 1e9 + 7;

public:
    int numOfWays(int n, int x = 0, int y = 0, int z = 0)
    {
        if (!n)
            return 1;
        if (dp[n][x][y][z] != 0)
            return dp[n][x][y][z];

        int ans = 0;
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3 && i != x; j++)
                for (int k = 1; j != y && j != i && k <= 3; k++)
                    if (k != z && k != j)
                        ans = (ans + numOfWays(n - 1, i, j, k)) % mod;
        return dp[n][x][y][z] = ans;
    }
};