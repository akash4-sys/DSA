#include "../../headers.h"

class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        int profit = 0, minP = INT_MAX;
        vector<int> v;
        for(int i = 0; i < p.size(); i++)
        {
            if(i != 0 && p[i] > p[i-1])
                v.push_back(p[i] - p[i-1]);
            
            minP = min(minP, p[i]);
            profit = max(profit, p[i] - minP);
        }

        if(v.empty())
            return 0;
        sort(v.begin(), v.end(), greater<int>());
        return max(v[0] + v[1], profit);
    }
};