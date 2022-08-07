#include "headers.h"

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) 
    {
        int i = 0, ans = 0, j = 1;
        while(i < nums.size() && j < nums.size())
        {
            if(nums[j] - nums[i] < diff)
            {
                j++;
                continue;
            }
            else if(nums[j] - nums[i] > diff)
            {
                i++;
                continue;
            }
            else if(nums[j] - nums[i] == diff)
            {
                int k = j + 1;
                while(k < nums.size())
                {
                    if(nums[k] - nums[j] == diff)
                    {
                        ans++;
                        break;
                    }
                    k++;
                }
            }
            i++;
            j = i+1;
        }

        return ans;
    }
};