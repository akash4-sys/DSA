#include "../../headers.h"

class Solution
{
public:
    bool xorGame(vector<int> &v)
    {
        int x = 0;
        for(int n: v)
            x ^= n;
        return !x || !(v.size() & 1);
    }
};


// @lc app=leetcode id=810 lang=cpp