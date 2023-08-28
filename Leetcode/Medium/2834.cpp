#include "../headers.h"

// Time Complexity - O(1)
// Space Complexity - O(1)

class Solution
{
public:
    long long minimumPossibleSum(int n, int t)
    {
        long long l = t / 2, sumOfHalf = l * (l + 1) / 2;
        if (n <= l)
            return n * (n + 1) / 2;
        long long a = t - 1, sumBeforeT = a * (a + 1) / 2, r = t + n - l - 1;
        long long total = r * (r + 1) / 2;
        return total - (sumBeforeT - sumOfHalf);
    }
};


// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    long long minimumPossibleSum(int n, int t)
    {
        long long ans = 0;
        for (int i = 1; i <= t - i && n; i++)
            ans += i, n--;
        
        while (n--)
            ans += t++;
        return ans;
    }
};