#include "../../headers.h"

class Solution
{
public:
    int sumSubarrayMins(vector<int> &v)
    {
        long ans = 0, mod = 1e9 + 7, n = v.size();
        stack<int> st;
        for(int i = 0; i <= n; i++)
        {
            while(!st.empty() && v[st.top()] > (i == n ? INT_MIN : v[i]))
            {
                int j = st.top(); 
                st.pop();
                int k = st.empty() ? -1 : st.top();
                ans += (long)v[j] * (i - j) * (j - k);
            }
            st.push(i);
        }
        return ans % mod;
    }
};

// @lc app=leetcode id=907 lang=cpp