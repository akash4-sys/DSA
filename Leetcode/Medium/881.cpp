#include "../../headers.h"

class Solution
{
public:
    int numRescueBoats(vector<int> &v, int k)
    {
        int ans = 0;
        sort(v.begin(), v.end(), greater<int>());
        for (int i = 0, j = v.size() - 1; i <= j; i++, ans++)
            if (v[i] + v[j] <= k)
                j--;
        return ans;
    }
};

// @lc app=leetcode id=881 lang=cpp