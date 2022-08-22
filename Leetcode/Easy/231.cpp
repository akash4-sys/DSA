#include "../../headers.h"

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if(n <= 0)
            return false;
        return long(log2(n)) == double(log2(n));
    }
};