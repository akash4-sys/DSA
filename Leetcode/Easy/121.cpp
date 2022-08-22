#include "../../headers.h"

class Solution
{
public:
    int maxProfit(vector<int> &p)
    {
        int ans = 0, minP = INT_MAX;
        for (int i = 0; i < p.size(); i++)
        {
            minP = min(minP, p[i]);
            ans = max(p[i] - minP, ans);
        }
        return ans;
    }
};