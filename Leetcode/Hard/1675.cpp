#include "headers.h"

class Solution
{
public:
    int minimumDeviation(vector<int> &v)
    {
        int ans = INT_MAX, mini = ans;
        priority_queue<int> pq;
        for (int n : v)
        {
            n = n % 2 ? n * 2 : n;
            pq.push(n);
            mini = min(mini, n);
        }
        
        while (pq.top() % 2 == 0)
        {
            ans = min(ans, pq.top() - mini);
            mini = min(mini, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop();
        }
        return min(ans, pq.top() - mini);
    }
};

//  @lc app=leetcode id=1675 lang=cpp