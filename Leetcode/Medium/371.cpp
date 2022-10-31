#include "../../headers.h"

class Solution
{
public:
    int getSum(int a, int b)
    {
        return b ? getSum(a ^ b, (unsigned)(a & b) << 1) : a;
    }
};