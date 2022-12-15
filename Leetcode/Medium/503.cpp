#include "../../headers.h"

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &v)
    {
        int n = v.size();
        vector<int> ans(n, -1), st;
        for (int i = 0; i < n * 2; i++)
        {
            while(!st.empty() && v[st.back()] < v[i % n])
                ans[st.back()] = v[i % n], st.pop_back();
            if(i < n)
                st.push_back(i % n);
        }
        return ans;
    }
};


// @lc app=leetcode id=503 lang=cpp