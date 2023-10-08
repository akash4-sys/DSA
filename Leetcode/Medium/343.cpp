#include "../../headers.h"

class Solution
{
public:
    int integerBreak(int n)
    {
        if (n <= 3)
            return n - 1;

        int two = n / 2, three = 0;
        if (n % 2)
            two--, three++;
        three += ((two / 3) * 2);
        two %= 3;
        return pow(2, two) * pow(3, three);
    }
};


class Solution
{
public:
    int integerBreak(int n)
    {
        if(n <= 3)
            return n-1;
        if(n == 4)
            return 4;
        int p = 1;
        while(n > 4)
            p *= 3, n -= 3;
        p *= n;
        return p;
    }
};