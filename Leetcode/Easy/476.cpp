#include "../../headers.h"

// One's Complement
class Solution
{
public:
    int findComplement(int n)
    {
        return ~(-1u << int(log2(n))+1) ^ n; 
        // or return ~(-1u << (32 - __builtin_clz(num))) ^ num;

        // won't work for too large integer value
        // for(int i = 1; i <= n; i <<= 1)
        //     n ^= i;
        // return n;
    }
};