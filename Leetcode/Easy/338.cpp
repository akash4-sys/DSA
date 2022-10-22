#include "../../headers.h"

// easy way out
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> bin(n + 1, 0);
        for (int i = 1; i <= n; i++)
            bin[i] = __builtin_popcount(i);
        return bin;
    }
};



// Time Complexity O(n)
// Space Complexity O(n)

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> bin(n + 1, 0);
        for (int i = 1; i <= n; i++)
            bin[i] = (i % 2 == 0) ? bin[i / 2] : bin[i / 2] + 1;
        return bin;
    }
};

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++)
            ans[i] = (i & 1) ? ans[i - 1] + 1 : ans[i >> 2];
        return ans;
    }
};