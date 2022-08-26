#include "../../headers.h"

class Solution
{
public:
    int maxResult(vector<int> &v, int k)
    {
        vector<int> dp(v.size());
        dp[0] = v[0];
        deque<int> q{0};
        for(int i = 1; i < v.size(); i++)
        {
            if(q.front() < i -k)
                q.pop_front();
            dp[i] = v[i] + dp[q.front()];
            while(!q.empty() && dp[q.back()] <= dp[i])
                q.pop_back();
            q.push_back(i);
        }
        return dp.back();
    }
};