#include "../../headers.h"

// @lc app=leetcode id=658 lang=cpp

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &v, int k, int x)
    {
        int l = 0, r = v.size() - 1;
        while(r - l >= k)
            if(x - v[l] <= v[r] - x)
                r--;
            else l++;
        return vector<int>(v.begin() + l, v.begin() + r + 1);
    }
};

