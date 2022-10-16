#include "../../headers.h"

class Solution
{
    int calc(int n)
    {
        int x = n & 3;
        if(!x)
            return n;
        if(x == 1)
            return 1;
        if(x == 2)
            return n + 1;
        return 0;
    }
public:
    int xorOperation(int n, int start)
    {
        return (start & 1 & n) | ((calc((start >> 1) + n - 1) ^ calc((start >> 1) - 1)) << 1);
    }
};



class Solution
{
public:
    int xorOperation(int n, int s)
    {
        int ans = s;
        for (int i = 1; i < n; i++)
            ans ^= (s + (2 * i));
        return ans;
    }
};