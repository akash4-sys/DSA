#include "../../headers.h"

class Solution
{
public:
    int factorial(int n)
    {
        if (n == 0)
            return 1;
        return n * factorial(n - 1);
    }

    int countNumbersWithUniqueDigits(int digits)
    {
        if (digits > 10)
            return 0;

        digits++;
        int fact9 = 362880, ans = 1;
        while (digits--)
            ans += (9 * (fact9 / factorial(10 - digits)));

        return ans;
    }
};