#include "headers.h"

class Solution
{
public:
    int commonFactors(int a, int b)
    {
        int x = gcd(a, b), ans = 0;
        for (int i = 1; i <= sqrt(x); i++)
        {
            if(x % i == 0)
                if(x /i == i)
                    ans += 1;
                else ans += 2;
        }
        return ans;
    }
};