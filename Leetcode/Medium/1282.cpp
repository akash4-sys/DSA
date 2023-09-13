#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &v)
    {
        vector<vector<int>> grp(v.size() + 1), ans;
        for (int i = 0; i < v.size(); i++)
            grp[v[i]].push_back(i);
        
        for (int i = 1; i < grp.size(); i++)
            if (grp[i].size() == i)
                ans.push_back(grp[i]);
            else
            {
                for (int j = 0; j < grp[i].size(); j++) {
                    if (j % i == 0)
                        ans.push_back({});
                    ans.back().push_back(grp[i][j]);
                }
            }
        return ans;
    }
};

// @lc app=leetcode id=1282 lang=cpp