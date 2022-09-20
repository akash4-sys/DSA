#include "../../headers.h"

class Solution
{
    int primes[3] = {2, 3, 5};
public:
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        for(int p: primes)
            while(n % p == 0)
                n /= p;
        return n == 1;
    }
};