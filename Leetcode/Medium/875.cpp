#include "../../headers.h"

class Solution
{
    bool canEat(vector<int> &v, int speed, int time)
    {
        double t = 0;
        for (int n : v)
        {
            t = ceil(t);
            t += (double)n / speed;
            if (time < t)
                return 0;
        }
        return 1;
    }

public:
    int minEatingSpeed(vector<int> &v, int h)
    {
        int r = *max_element(v.begin(), v.end()), l = 0, ans = 0;
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            if (canEat(v, mid, h))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        return ans;
    }
};

// @lc app=leetcode id=875 lang=cpp