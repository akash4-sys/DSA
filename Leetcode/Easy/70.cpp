#include "../../headers.h"

class Solution 
{
public:
    int climbStairs(int n) 
    {
        int curr = 1, last = 1;
        while(n-- > 1)
        {
            int next = curr + last;
            last = curr;
            curr = next;
        }
        return curr;
    }
};

// Recursive
// Gives TLE
class Solution
{
    int ans = 0;
public:
    int climbStairs(int n, int sum = 0)
    {
        if (n == 1)
            return n;
        if (sum >= n)
            return ans += (sum == n);
        climbStairs(n, sum + 1);
        climbStairs(n, sum + 2);
        return ans;
    }
};


// Recursive Not TLE

class Solution
{
    int ans = 1, last = 1, latest = 2, i = 2;
public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
            return n;
        ans = last + latest;
        last = latest;
        latest = ans;
        if(++i < n)
            climbStairs(n);
        return ans;
    }
};