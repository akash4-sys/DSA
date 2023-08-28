#include "../../headers.h"

class Solution
{
public:
    long long maxRunTime(int n, vector<int> &v)
    {
        long long l = 1, r = accumulate(v.begin(), v.end(), 0LL) / n;
        while (l <= r)
        {
            long long mid = l + ((r - l) / 2), sum = 0;
            for (int p : v)
                sum += min((long long)p, mid);
            (sum >= n * mid) ? l = mid + 1 : r = mid - 1;
        }
        return l - 1;
    }
};

// @lc app=leetcode id=2141 lang=cpp