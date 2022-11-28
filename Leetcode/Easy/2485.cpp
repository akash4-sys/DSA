#include "headers.h"

class Solution
{
public:
    int pivotInteger(int n)
    {
        int ans = -1;
        for(int i = 1; i <= n; i++)
        {
            int s = 0, x = 0;
            for(int j = 1; j <= i; j++)
                s += j;
            for(int j = i; j <= n; j++)
                x += j;
            if(s == x)
                return i;
        }
        return ans;
    }
};