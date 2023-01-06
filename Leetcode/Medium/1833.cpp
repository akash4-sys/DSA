#include "../../headers.h"

class Solution
{
public:
    int maxIceCream(vector<int> &v, int k)
    {
        sort(begin(v), end(v));
        for (int i = 0; i < v.size(); ++i)
            if (k >= v[i])
                k -= v[i];
            else
                return i;
        return v.size();
    }
};

// @lc app=leetcode id=1833 lang=cpp