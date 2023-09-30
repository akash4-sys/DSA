#include "../../headers.h"

class Solution
{
public:
    int minAbsoluteDifference(vector<int> &v, int x)
    {
        int ans = INT_MAX;
        set<int> st;
        for (int i = x; i < v.size(); i++)
        {
            st.insert(v[i - x]);
            auto it = st.upper_bound(v[i]);
            if (it != st.begin())
                ans = min(ans, v[i] - *prev(it));
            if (it != st.end())
                ans = min(ans, *it - v[i]);
        }
        return ans;
    }
};

// @lc app=leetcode id=2817 lang=cpp