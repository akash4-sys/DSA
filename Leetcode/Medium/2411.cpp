#include "headers.h"

class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &n)
    {
        vector<int> ans(n.size(), 1), bit(30, 0);
        for(int i = n.size()-1; i >= 0; i--)
            for(int j = 0; j < 30; j++)
            {
                if(n[i] & (1 << j))
                    bit[j] = i;
                ans[i] = max(ans[i], bit[j] - i + 1);
            }
        return ans;
    }
};