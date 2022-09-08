#include "../../headers.h"

// Iterative
// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        int last = 0, latest = 1;
        for (int i = 2; i <= n; i++)
        {
            int sum = latest + last;
            last = latest;
            latest = sum;
        }
        return latest;
    }
};

// recursive
// Time Complexity - O(N)
// Space Complexity - O(N) -- taking recursion stack space in account

class Solution
{
    int last = 1, lastlast = 0, ans = 0, i = 2;
public:
    int fib(int n)
    {
        ans = last + lastlast;
        lastlast = last;
        last = ans;
        if(i == n)
            return ans;
        ++i;
        fib(n);
    }
};