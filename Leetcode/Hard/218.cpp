#include "../../headers.h"

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &b)
    {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> pq;
        int i = 0, sz = b.size();
        while (i < sz || !pq.empty())
        {
            int curX;
            if (i == sz || !pq.empty() && pq.top().second < b[i][0])
            {
                curX = pq.top().second;
                while (!pq.empty() && pq.top().second <= curX)
                    pq.pop();
            }
            else
            {
                curX = b[i][0];
                while (i < sz && b[i][0] == curX)
                    pq.push({b[i][2], b[i][1]}), i++;
            }
            int curH = pq.empty() ? 0 : pq.top().first;
            if(ans.empty() || ans.back()[1] != curH)
                ans.push_back({curX, curH});
        }
        return ans;
    }
};

// @lc app=leetcode id=218 lang=cpp