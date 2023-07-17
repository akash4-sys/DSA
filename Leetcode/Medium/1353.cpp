#include "../../headers.h"

class Solution
{
public:
    int maxEvents(vector<vector<int>> &v)
    {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(v.begin(), v.end());
        for (int d = 1, i = 0; d <= 100000; d++)
        {
            while (pq.size() && pq.top() < d)
                pq.pop();
            while (i < v.size() && v[i][0] == d)
                pq.push(v[i++][1]);
            if (pq.size())
                pq.pop(), ans++;
        }
        return ans;
    }
};

// @lc app=leetcode id=1353 lang=cpp