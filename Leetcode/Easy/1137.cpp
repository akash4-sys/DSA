#include "../../headers.h"

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        int latest = 1, seclast = 1, last = 0, sum;
        for (int i = 3; i <= n; i++)
        {
            sum = latest + seclast + last;
            last = seclast;
            seclast = latest;
            latest = sum;
        }
        return latest;
    }
};



// Recursive
class Solution
{
    int ans = 0, last = 1, ll = 1, lll = 0, i = 3;
public:
    int tribonacci(int n)
    {
        if(!n || n == 1 || n == 2)
            return n != 0;
        ans = last + ll + lll;
        lll = ll;
        ll = last;
        last = ans;
        if(++i <= n)
            tribonacci(n);
        return last;
    }
};