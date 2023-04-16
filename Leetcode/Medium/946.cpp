#include "../../headers.h"

class Solution
{
public:
    bool validateStackSequences(vector<int> &push, vector<int> &pop)
    {
        stack<int> st;
        for (int i = 0, j = 0; i < push.size(); i++)
        {
            st.push(push[i]);
            while (!st.empty() && st.top() == pop[j])
                st.pop(), j++;
        }
        return st.empty();
    }
};

// @lc app=leetcode id=946 lang=cpp