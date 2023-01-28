#include "../../headers.h"

class SummaryRanges
{
    set<int> st;
public:
    SummaryRanges()
    {
        st = {};
    }

    void addNum(int x)
    {
        st.insert(x);
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> ans;
        auto it = st.begin();
        int x = *it + 1;
        ans.push_back({*it++});
        
        for (; it != st.end(); it++, x++)
            if (*it != x)
            {
                ans.back().push_back(x - 1);
                x = *it;
                ans.push_back({x});
            }
        ans.back().push_back(*--it);
        return ans;
    }
};


class SummaryRanges
{
    vector<int> v;
public:
    SummaryRanges()
    {
        v = {};
    }

    void addNum(int x)
    {
        v.push_back(x);
    }

    vector<vector<int>> getIntervals()
    {
        sort(v.begin(), v.end());
        auto ip = unique(v.begin(), v.end());
        v.resize(distance(v.begin(), ip));
        vector<vector<int>> ans;
        ans.push_back({v[0]});

        for (int i = 1, x = v[0] + 1; i < v.size(); i++, x++)
            if (v[i] != x)
            {
                ans.back().push_back(x - 1);
                x = v[i];
                ans.push_back({x});
            }
        ans.back().push_back(v.back());
        return ans;
    }
};

// @lc app=leetcode id=352 lang=cpp