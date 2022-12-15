#include "../../headers.h"

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &a, vector<int> &b)
    {
        unordered_map<int, int> ump;
        vector<int> ans, st;
        for (int n : b)
        {
            while(!st.empty() && st.back() < n)
                ump[st.back()] = n, st.pop_back();
            st.push_back(n);
        }
        
        for (int n : a)
            ans.push_back(ump.count(n) ? ump[n] : -1);
        return ans;
    }
};

// @lc app=leetcode id=496 lang=cpp