#include "../../headers.h"

class Solution
{
public:
    int countOrders(int n)
    {
        long long mod = 1e9 + 7, ans = 1;
        for (int i = 1; i <= n; i++)
            (ans *= (i * (i * 2 - 1))) %= mod;
        return ans;
    }
};