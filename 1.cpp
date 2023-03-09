#include "headers.h"

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