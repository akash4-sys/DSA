#include "../../headers.h"

class Solution
{
    int dirs[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    double dp[26][26][101];

    double onBoard(int n, int i, int j)
    {
        double cnt = 0;
        for (auto [x, y] : dirs)
            cnt += (i + x >= 0 && i + x < n && j + y >= 0 && j + y < n);
        return cnt;
    }

    double cntAfterKMoves(int n, int k, int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= n)
            return 0;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        if (k == 1)
            return onBoard(n, i, j);

        double cnt = 0.0;
        for (auto [x, y] : dirs)
            cnt += cntAfterKMoves(n, k - 1, i + x, j + y);
        return dp[i][j][k] = cnt;
    }

public:
    double knightProbability(int n, int k, int i, int j)
    {
        if (!k)
            return 1;
        
        fill_n(&dp[0][0][0], 26 * 26 * 101, -1.0);
        long double totalEvents = pow(8, k);
        return cntAfterKMoves(n, k, i, j) / totalEvents;
    }
};