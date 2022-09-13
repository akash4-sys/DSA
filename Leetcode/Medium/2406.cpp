#include "headers.h"

class Solution
{
public:
    int minGroups(vector<vector<int>> &v)
    {
        sort(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto n: v)
        {
            if(!pq.empty() && pq.top() < n[0])
                pq.pop();
            pq.push(n[1]);
        }
        return pq.size();
    }
};