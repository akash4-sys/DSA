#include "../../headers.h"

class Solution
{
    int n, dp[61][65537];
    vector<int> ans;
    void rec(vector<int> &skill, vector<int> &res, int req, int i)
    {
        if (req == (1 << n) - 1)
        {
            if (ans.empty() || res.size() < ans.size())
                ans = res;
            return;
        }
        if (i == skill.size() || (dp[i][req] != -1 && dp[i][req] < res.size()))
            return;

        res.push_back(i);
        rec(skill, res, req | skill[i], i + 1);
        res.pop_back();
        rec(skill, res, req, i + 1);
        if (res.size() > 0)
            dp[i][req] = res.size();
    }
    
public:
    vector<int> smallestSufficientTeam(vector<string> &v, vector<vector<string>> &p)
    {
        memset(dp, -1, sizeof(dp));
        n = v.size();
        vector<int> res;

        unordered_map<string, int> req;
        for (int i = 0; i < n; i++)
            req[v[i]] = i;
        
        vector<int> skills(p.size(), 0);
        for (int i = 0; i < p.size(); i++)
            for (string &s : p[i])
                skills[i] |= (1 << req[s]);
        
        rec(skills, res, 0, 0);
        return ans;
    }
};

// @lc app=leetcode id=1125 lang=cpp