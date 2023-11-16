#include "../../headers.h"

class Solution
{
public:
    long long distributeCandies(int n, int m)
    {
        long long ans = 0;
        for (int i = 0; i <= min(m, n + 1); i++)
        {
            int rem = n - i;
            long long b = rem / 2, c = rem % 2 == 0 ? b : b + 1;
            long long mx = min(rem, m);
            long long ways = mx >= b ? (mx - b) + (mx - c) + 1 : 0;
            ans += ways;
        }
        return ans;
    }
};