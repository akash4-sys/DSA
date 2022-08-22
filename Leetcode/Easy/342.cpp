#include "../../headers.h"

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if(n <= 0)
            return false;
        double x = log2(n) / log2(4);
        int y = log2(n) / log2(4);
        return x == y;
    }
};