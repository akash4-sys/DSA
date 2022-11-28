#include "../../headers.h"

class Solution 
{
public:
    vector<vector<int>> findWinners(vector<vector<int>>& edges) 
    {
        vector<vector<int>> ans(2);
        map<int, int> indegree;
        for(auto e: edges)
        {
            if(indegree[e[0]]);
            indegree[e[1]]++;
        }

        for(auto [e, in]: indegree)
            if(!in)
                ans[0].push_back(e);
            else if(in == 1)
                ans[1].push_back(e);
        return ans;
    }
};

// @lc app=leetcode id=2225 lang=cpp