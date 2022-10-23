#include "../../headers.h"

// cyclic sort

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &v)
    {
        vector<int> ans(2, -1);
        for(int i = 0; i < v.size(); i++)
            while(v[i] != i + 1)
                if(v[i] == v[v[i] - 1])
                {
                    ans = {v[i], i+1};
                    break;
                }
                else
                    swap(v[i], v[v[i] - 1]);
        return ans;
    }
};

// @lc app=leetcode id=645 lang=cpp