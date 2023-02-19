#include "headers.h"

class Solution
{
    bool check(int x)
    {
        for (int i = 2; i <= 30; i++)
            if (x % (i * i) == 0)
                return 0;
        return 1;
    }

    bool free(int x)
    {
        if (x == 1)
            return 1;
        int sq = sqrt(x);
        if (sq * sq == x)
            return 0;
        for (int i = 1; i <= sq; i++)
            if (x % i == 0)
            {
                if (x / i != i && !check(x / i))
                    return 0;
                if (!check(i))
                    return 0;
            }
        return 1;
    }

public:
    int squareFreeSubsets(vector<int> &v)
    {
        long long mod = 1e9 + 7, mul = 1;
        vector<int> ans(v.size(), 0);
        for (int i = 0; i < v.size(); i++)
            if (free(v[i]))
            {
                long long x = (mul * v[i]) % mod;
                if (check(x))
                {
                    mul = x;
                    ans[i] = i - 1 >= 0 ? ans[i - 1] + 1 : 1;
                }
            }
        return ans.back();
    }
};