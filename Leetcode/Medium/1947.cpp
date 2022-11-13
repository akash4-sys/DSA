#include "../../headers.h"

class Solution
{
    int ans = 0, vis = 0;
public:
    int maxCompatibilitySum(vector<vector<int>> &s, vector<vector<int>> &m, int i = 0, int sc = 0)
    {
        if(i == s.size())
            return ans = max(ans, sc);
        for(int j = 0; j < s.size(); j++)
        {
            if(vis & (1 << j))
                continue;
            vis |= (1 << j);
            int curr = 0;
            for(int k = 0; k < s[0].size(); k++)
                curr += s[i][k] == m[j][k];
            maxCompatibilitySum(s, m, i + 1, sc + curr);
            vis ^= (1 << j);
        }
        return ans;
    }
};


// @lc app=leetcode id=1947 lang=cpp