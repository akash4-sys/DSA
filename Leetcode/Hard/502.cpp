#include "../../headers.h"

class Solution
{
public:
    int findMaximizedCapital(int k, int cap, vector<int> &profits, vector<int> &capital)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < profits.size(); i++)
            v.push_back({capital[i], profits[i]});
        
        sort(v.begin(), v.end());
        priority_queue<int> pq;
        int i = 0;
        while (k--)
        {
            while(i < v.size() && cap >= v[i].first)
                pq.push(v[i++].second);
            if (!pq.empty())
                cap += pq.top(), pq.pop();
        }
        return cap;
    }
};

// @lc app=leetcode id=502 lang=cpp