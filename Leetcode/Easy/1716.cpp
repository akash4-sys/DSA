#include "../../headers.h"

class Solution
{
public:
    int totalMoney(int n)
    {
        if (n <= 7)
            return n * (n + 1) / 2;

        long long weeks = n / 7, r = n % 7, ans = 0;
        for (int i = 0; i < weeks; i++)
            ans += (28 + (i * 7));
        long long leftover = weeks * (weeks + 1) / 2, l = weeks + r;
        long long full = l * (l + 1) / 2;
        ans += r ? full - leftover : 0;
        return ans;
    }
};