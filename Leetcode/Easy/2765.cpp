#include "headers.h"

class Solution
{
public:
    int alternatingSubarray(vector<int> &v)
    {
        int ans = -1;
        for (int i = 1, j = 0, x = 1; i < v.size(); i++)
        {
            int d = v[i] - v[i - 1];
            if ((x && d == 1) || (!x && d == -1))
                ans = max(ans, i - j + 1), x ^= 1;
            else
                j = i - (d == 1), x = !(d == 1);
        }
        return ans;
    }
};

// @lc app=leetcode id=2765 lang=cpp