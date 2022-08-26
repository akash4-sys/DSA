#include "../../headers.h"

class Solution
{
public:
    int longestSubarray(vector<int> &v, int limit)
    {
        deque<int> minq, maxq;
        int l = 0, r;
        for(r = 0; r < v.size(); ++r)
        {
            while(!minq.empty() && minq.back() > v[r])
                minq.pop_back();
            while(!maxq.empty() && maxq.back() < v[r])
                maxq.pop_back();
            
            minq.push_back(v[r]);
            maxq.push_back(v[r]);

            if(maxq.front() - minq.front() > limit)
            {
                if(maxq.front() == v[l])
                    maxq.pop_front();
                if(minq.front() == v[l])
                    minq.pop_front();
                ++l;
            }
        }
        return r - l;
    }
};