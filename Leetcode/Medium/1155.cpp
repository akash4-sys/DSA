#include "../../headers.h"

// Time complexity(O(n * l * t))
class Solution
{
public:
    int numRollsToTarget(int n, int l, int t)
    {
        vector<int> v(t + 1, 0);
        int j, mod = 1e9 + 7;
        v[0] = 1;
        for(int i = 1; i <= n; i++)
            for(int k = t; k >= (i == n ? t : 0); --k)
                for(j = k - 1, v[k] = 0; j >= max(0, k - l); --j)
                    v[k] = (v[k] + v[j]) % mod;
        return v[t];
    }
};

// Time complexity(O(n * l * t))
class Solution
{
    int mod = 1e9 + 7;
public:
    int numRollsToTarget(int n, int l, int t)
    {
        vector<vector<int>> v(n + 1, vector<int>(t + 1, 0));
        v[0][0] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= t; j++)
                for(int k = 1; k <= l; k++)
                    v[i][j] = (v[i][j] + (k <= j ? v[i - 1][j - k] : 0)) % mod;
        return v[n][t];
    }
};

// @lc app=leetcode id=1155 lang=cpp