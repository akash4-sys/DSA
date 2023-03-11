#include "headers.h"

class Solution
{
public:
    int passThePillow(int n, int t)
    {
        int r = t % (--n), q = t / n;
        return q % 2 ? (n - r) + 1 : r + 1;
    }
};


class Solution
{
public:
    int passThePillow(int n, int t)
    {
        int d = 1, i = 1;
        while (t)
        {
            if (d)
                for (; i < n && t; i++, t--);
            else
                for (; i > 1 && t; i--, t--);
            d ^= 1;
        }
        return i;
    }
};