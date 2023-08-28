#include "../../headers.h"

// Time Complexity - O(N^3)
// Space Complexity - O(N^2)

class Solution
{
    int dirs[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
public:
    double knightProbability(int n, int moves, int r, int c)
    {
        if (!moves)
            return 1;
        vector prev(n, vector<long double>(n, 0.0)), curr = prev;
        long double totalEvents = pow(8, moves), favEvents = 0;

        prev[r][c] = 1;
        for (int k = 1; k <= moves; k++)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    curr[i][j] = 0;
                    for (auto [x, y] : dirs)
                        if (i + x >= 0 && i + x < n && j + y >= 0 && j + y < n)
                            curr[i][j] += prev[i + x][j + y];
                }
            prev = curr;
        }

        for (auto &row : prev)
            for (auto &cnt: row)
                favEvents += cnt;
        return favEvents / totalEvents;
    }
};

// Time Complexity - O(N^3)
// Space Complexity - O(N^3)

class Solution
{
    int dirs[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

public:
    double knightProbability(int n, int moves, int r, int c)
    {
        if (!moves)
            return 1;
        vector dp(n, vector(n, vector<long double>(moves + 1, 0.0)));
        long double totalEvents = pow(8, moves), favEvents = 0;

        dp[r][c][0] = 1;
        for (int k = 1; k <= moves; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    for (auto [x, y] : dirs)
                        if (i + x >= 0 && i + x < n && j + y >= 0 && j + y < n)
                            dp[i][j][k] += dp[i + x][j + y][k - 1];
                    favEvents += dp[i][j][moves];
                }
        return favEvents / totalEvents;
    }
};

// Time Complexity - O(N^3)
// Space Complexity - O(N^3)

class Solution
{
    int dirs[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    double dp[26][26][101];

    double cntAfterKMoves(int n, int k, int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= n || !k)
            return 0;
        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        double cnt = 0.0;
        for (auto [x, y] : dirs)
            if (k == 1)
                cnt += (i + x >= 0 && i + x < n && j + y >= 0 && j + y < n);
            else
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


// Time Complexity - O(N^3)
// Space Complexity - O(N^3)

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