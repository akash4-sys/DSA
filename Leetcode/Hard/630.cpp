#include "../../headers.h"

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &v)
    {
        int currT = 0;
        sort(v.begin(), v.end(), [](auto v1, auto v2){ return v1[1] < v2[1]; });
        priority_queue<int> pq;
        for(auto n: v)
        {
            if(currT + n[0] <= n[1])
                currT += n[0], pq.push(n[0]);
            else if(!pq.empty() && pq.top() > n[0])
                currT += n[0] - pq.top(), pq.pop(), pq.push(n[0]);
        }
        return pq.size();
    }
};

//  @lc app=leetcode id=630 lang=cpp