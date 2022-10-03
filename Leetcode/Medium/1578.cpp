#include "../../headers.h"

class Solution
{
public:
    int minCost(string s, vector<int> &t)
    {
        int ans = 0, c = t[0];
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] != s[i - 1])
                c = 0;
            ans += min(c, t[i]);
            c = max(c, t[i]);
        }
        return ans;
    }
};

// @lc app=leetcode id=1578 lang=cpp