#include "../../headers.h"

class Solution
{
public:
    int maximumXOR(vector<int> &v)
    {
        int x = 0;
        for(int n: v)
            x |= n;
        return x;
    }
};

// @lc app=leetcode id=2317 lang=cpp