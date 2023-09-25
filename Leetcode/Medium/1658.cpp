#include "../../headers.h"

class Solution
{
public:
    int minOperations(vector<int> &v, int x)
    {
        int total = accumulate(v.begin(), v.end(), 0), sum = 0, ans = INT_MAX;
        for (int i = 0, j = 0, n = v.size(); i < n; i++)
        {
            sum += v[i];
            while (j <= i && total - sum < x)
                sum -= v[j++];
            if (total - sum == x)
                ans = min(ans, n - (i - j + 1));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

// @lc app=leetcode id=1658 lang=cpp