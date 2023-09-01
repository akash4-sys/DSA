#include "../../headers.h"

class Solution
{
public:
    long long minimumReplacement(vector<int> &v)
    {
        long long ans = 0;
        for (int i = v.size() - 2; i >= 0; i--)
            if (v[i] > v[i + 1])
            {
                long long n = ceil((v[i] + v[i + 1] - 1LL) / v[i + 1]);
                ans += n - 1;
                v[i] /= n;
            }
        return ans;
    }
};

// @lc app=leetcode id=2366 lang=cpp