#include "headers.h"

class Solution
{
public:
    int alternateDigitSum(int n)
    {
        int ans = 0, sign = 1;
        for (; n; n /= 10)
        {
            sign *= -1;
            ans += sign * n % 10;
        }
        return ans * sign;
    }
};