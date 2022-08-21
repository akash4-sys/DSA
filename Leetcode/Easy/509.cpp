#include "../../headers.h"


// Iterative
class Solution
{
public:
    int fib(int n)
    {
        if(n == 0)
            return 0;
        int last = 0, latest = 1;
        for(int i = 2; i <= n; i++)
        {
            int sum = latest + last;
            last = latest;
            latest = sum;
        }
        return latest;
    }
};


// recursive
class Solution
{
    int last = 0, latest = 1;
    int recurse(int i, int n)
    {
        if (i > n)
            return latest;
        int sum = latest + last;
        last = latest;
        latest = sum;
        return recurse(++i, n);
    }

public:
    int fib(int n)
    {
        if(n == 0)
            return 0;
        return recurse(0, n);
    }
};