#include "../../headers.h"

class Solution
{
public:
    int minSubArrayLen(int t, vector<int> &v)
    {
        int ans = INT_MAX, l = 0, sum = 0;
        for(int r = 0; r < v.size(); r++)
        {
            sum += v[r];
            while(sum >= t)
            {
                ans = min(ans, r - l + 1);
                sum -= v[l++];
            }
        }
        return ans;
    }
};