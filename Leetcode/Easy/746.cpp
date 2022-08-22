#include "../../headers.h"

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &c)
    {
        int latest = c[1], last = c[0];
        if(c.size() <= 2)
            return min(latest, last);
        
        for(int i = 2; i < c.size(); i++)
        {
            int curr = c[i] + min(latest, last);
            last = latest;
            latest = curr;
        }
        return min(latest, last);
    }
};