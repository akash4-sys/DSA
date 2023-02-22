#include "headers.h"

class Solution
{
public:
    int minOperations(int n)
    {
        return __builtin_popcount(n ^ (n * 3));
    }
};

// Time Complexity - O(log(N))
// Space Complexity - O(1)

class Solution
{
public:
    int minOperations(int n)
    {
        int ans = 0;
        for (; n; ans++)
        {
            int x = pow(2, ceil(log(n) / log(2)));
            int y = pow(2, floor(log(n) / log(2)));
            if (x - n < n - y)
                n = x - n;
            else n -= y;
        }
        return ans;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)
class Solution
{
    unordered_map<int, int> mp;
public:
    int minOperations(int n)
    {
        if (n <= 1)
            return n;
        if (mp.count(n))
            return mp[n];
        if (n & (n - 1) == 0)
            return 1;
        int b = log(n) / log(2);
        mp[n] = minOperations(n - pow(2, b)) + 1;
        if ((pow(2, ++b) - n) < n)
            mp[n] = min(mp[n], minOperations(pow(2, b) - n) + 1);
        return mp[n];
    }
};