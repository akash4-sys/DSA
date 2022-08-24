#include "../../headers.h"

class Solution
{
public:
    int coinChange(vector<int> &coins, int n)
    {
        vector<int> v(n + 1, n + 10);
        v[0] = 0;

        for (int i = 1; i <= n; i++)
            for (int c : coins)
                if (i >= c)
                    v[i] = min(v[i], 1 + v[i - c]);
        return v[n] == n + 10 ? -1 : v[n];
    }
};