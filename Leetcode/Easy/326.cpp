#include "../../headers.h"

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        int x = pow(3, 19);
        return n > 0 && (x % n == 0);
    }
};