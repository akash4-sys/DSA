#include "../../headers.h"

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool n1 = dividend > 0, n2 = divisor > 0, neg = !(n1 ^ n2);
        if (n1)
            dividend = -dividend;
        if (n2)
            divisor = -divisor;

        vector<int> powersOfTwo, doubles;

        int powerOfTwo = -1;
        while (divisor >= dividend)
        {
            powersOfTwo.push_back(powerOfTwo);
            doubles.push_back(divisor);

            if (divisor < -1073741824)
                break;

            powerOfTwo += powerOfTwo;
            divisor += divisor;
        }

        int quotient = 0;
        for (int i = doubles.size() - 1; i >= 0; i--)
        {
            if(doubles[i] >= dividend)
            {
                quotient += powersOfTwo[i];
                dividend -= doubles[i];
            }
        }

        return neg ? -quotient : quotient;
    }
};