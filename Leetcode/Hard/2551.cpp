#include "headers.h"

class Solution 
{
public:
    long long putMarbles(vector<int>& v, int k) 
    {
        priority_queue<int> minq;
        priority_queue<int, vector<int>, greater<int>> maxq;
        for (int i = 0; i < v.size() - 1; i++) 
        {
            maxq.push(v[i] + v[i + 1]);
            minq.push(v[i] + v[i + 1]);
            if (minq.size() == k)
                minq.pop();
            if (maxq.size() == k)
                maxq.pop();
        }
        
        long long ans = 0;
        while (!maxq.empty()) 
        {
            ans += maxq.top() - minq.top();
            maxq.pop(); 
            minq.pop();
        }      
        return ans;
    }
};