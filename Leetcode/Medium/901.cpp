#include "../../headers.h"

class StockSpanner
{
    stack<pair<int, int>> st;
public:
    StockSpanner(): st(){}
    int next(int p)
    {
        int ans = 1;
        while(!st.empty() && st.top().first <= p)
            ans += st.top().second, st.pop();
        st.push({p, ans});
        return ans;
    }
};


// @lc app=leetcode id=901 lang=cpp