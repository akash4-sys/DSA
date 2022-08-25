#include "../../headers.h"

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int ans = 0, maxR = 0, l = 0, i = 0;
        while(l < nums.size()-1)
        {
            maxR = max(maxR, i + nums[i]);
            if(i == l)
                l = maxR, ans++;
            i++;
        }
        return ans;
    }
};