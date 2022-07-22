#include "../../headers.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        sort(begin(nums), end(nums));
        for(int i = 0; i < n; i++) 
        {
            int st = i+1, en = n-1, sum;
            while(st < en)
            {
                sum = nums[i] + nums[en] + nums[st];
                if(sum < target)
                    st++;
                else if(sum > target)
                    en--;
                else
                    return sum;
            }
            if(ans < target)
                ans = max(ans, sum);   
            else
                ans = min(ans, sum);
        }
        return ans;
    }
};