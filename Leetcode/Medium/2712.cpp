#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    long long minimumCost(string s)
    {
        long long ans = 0, n = s.size();
        for (int i = 1; i < n; i++)
            if (s[i] != s[i - 1])
                ans += min(i, (int)n - i);
        return ans;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    long long minimumCost(string s)
    {
        long long ans = 0;
        int n = s.size(), i = 0, j = n - 1;
        char l = s[0], r = s[n - 1];

        for (; i < j; i++, j--)
        {
            if (l != s[i])
                ans += i, l = s[i];
            if (r != s[j])
                ans += (n - j - 1), r = s[j];
        }

        if ((i != j && l != r) || (i == j && s[i] != l))
            ans += i;
        if (i == j && s[j] != r)
            ans += (n - j - 1);
        return ans;
    }
};