#include "headers.h"

class Solution
{
public:
    int minimizeXor(int x, int y)
    {
        int a = __builtin_popcount(x), b = __builtin_popcount(y), ans = x;
        for(int i = 0; i < 32; i++)
        {
            if(a > b && ((1 << i) & x) > 0)
                ans ^= 1 << i, a--;
            if(a < b && ((1 << i) & x) == 0)
                ans ^= 1 << i, a++;
        }
        return ans;
    }
};


class Solution 
{
public:
    int minimizeXor(int x, int y) 
    {
        int b = __builtin_popcount(y), A = 0;
        for(int i = 31; i >= 0 && b; i--)
            if(x & (1 << i))
                b--, A |= (1 << i);
        
        for(int i = 0; i <= 31 && b; i++)
            if((A & (1 << i)) == 0)
                b--, A |= (1 << i);

        return A;
    }
};