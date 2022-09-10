#include "../../headers.h"

// Time Complexity - O(N*K*2)
// Space Complexity - O(N*K*2)

class Solution
{
public:
    int maxProfit(int k, vector<int> &p)
    {
        vector<vector<int>> after(2, vector<int>(k+1, 0)), curr(2, vector<int>(k+1, 0));
        for(int i = p.size() - 1; i >= 0; i--)
        {
            for(int buy = 0; buy <= 1; buy++)
                for(int trans = 1; trans <= k; trans++)
                    if(buy)
                        curr[buy][trans] = max(-p[i] + after[0][trans], 0 + after[1][trans]);
                    else
                        curr[buy][trans] = max(p[i] + after[1][trans - 1], 0 + after[0][trans]);
                after = curr;
        }
        return after[1][k];
    }
};