#include "../../headers.h"

class Solution
{
public:
    int minimumAverageDifference(vector<int> &v)
    {
        int ans = -1, avg = INT_MAX, n = v.size();
        long suff = 0, pre = 0;
        for(auto &x: v)
            suff += x;

        for (int i = 0; i < n; i++)
        {
            pre += v[i];
            int a = pre / (i + 1), b = (i == n - 1) ? 0 : (suff - pre) / (n - i - 1);
            if (abs(a - b) < avg)
                avg = abs(a - b), ans = i;
        }
        return ans;
    }
};

// @lc app=leetcode id=2256 lang=cpp