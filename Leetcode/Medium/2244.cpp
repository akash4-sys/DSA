#include "../../headers.h"

class Solution
{
public:
    int minimumRounds(vector<int> &v)
    {
        unordered_map<int, int> mp;
        for (int n: v)
            mp[n]++;
        
        int ans = 0;
        for (auto &[n, c]: mp)
        {
            if (c < 2)
                return -1;
            ans += (c % 3) ? (c / 3) + 1 : (c / 3);
        }
        return ans;
    }
};

// @lc app=leetcode id=2244 lang=cpp