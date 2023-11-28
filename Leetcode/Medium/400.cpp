#include "../../headers.h"

class Solution
{
public:
    int findNthDigit(int n)
    {
        long long m = 1, d = 1;
        while (n - (m * d * 9) > 0)
            n -= (m * d * 9), d++, m *= 10;
        
        int i = n % d == 0 ? d : n % d;
        long long num = m + (n / d) - (i == d);
        for (int j = i; j < d; num /= 10, j++);
        return num % 10;
    }
};