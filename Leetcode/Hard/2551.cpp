#include "headers.h"

// Time Complexity - O(NlogN)
// Space Complxity - O(N)

class Solution
{
public:
    long long putMarbles(vector<int>& v, int k)
    {
        long long ans = 0;
        vector<long long> sum;
        for (int i = 1; i < v.size(); i++)
            sum.push_back(v[i - 1] + v[i]);
        
        sort(sum.begin(), sum.end());
        for (int i = 0; i < k - 1; i++)
            ans += (sum[sum.size() - i - 1] - sum[i]);
        return ans;
    }
};

// Time Complexity - O(NlogN)
// Space Complxity - O(N)

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