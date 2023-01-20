#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &v, vector<int> &line)
    {
        vector<vector<int>> ans;
        int n = v.size(), i = 0;
        while (i < n && v[i][1] < line[0])
            ans.push_back(v[i++]);
        while (i < n && line[1] >= v[i][0])
        {
            line[0] = min(line[0], v[i][0]);
            line[1] = max(line[1], v[i++][1]);
        }
        
        ans.push_back(line);
        while (i < n)
            ans.push_back(v[i++]);
        return ans;
    }
};

// @lc app=leetcode id=57 lang=cpp