#include "../../headers.h"

class Solution
{
    int f(char c) {
        return c == 'W' ? 1 : 0;
    }

public:
    bool canMakeSquare(vector<vector<char>> &g)
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
            {
                int cnt[2] = {0};
                cnt[f(g[i][j])]++;
                cnt[f(g[i][j + 1])]++;
                cnt[f(g[i + 1][j])]++;
                cnt[f(g[i + 1][j + 1])]++;
                if (cnt[0] == 3 || cnt[1] == 3 || cnt[0] == 0 || cnt[1] == 0)
                    return 1;
            }
        return 0;
    }
};