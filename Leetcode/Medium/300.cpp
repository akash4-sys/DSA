#include "../../headers.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> v;
        v.push_back(nums[0]);
        for(int n: nums)
        {
            if(n > v.back())
                v.push_back(n);
            else
            {
                int i = lower_bound(v.begin(), v.end(), n) - v.begin();
                v[i] = n;
            }
        }
        return v.size();
    }
};