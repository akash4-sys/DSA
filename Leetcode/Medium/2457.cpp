#include "headers.h"

class Solution
{
    int sum(long long n)
    {
        int ans = 0;
        for(; n; n /= 10)
            ans += (n % 10);
        return ans;
    }

public:
    long long makeIntegerBeautiful(long long n, int t)
    {
        long long N = n, base = 1;
        while(sum(n) > t)
            n = (n/10) + 1, base *= 10;
        return (n * base) - N;
    }
};