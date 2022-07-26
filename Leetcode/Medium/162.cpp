#include "../../headers.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;

        int st = 0, end = nums.size() - 1;
        while(st <= end) 
        {
            int mid = (st + end)/2;

            if(nums[mid] > nums[mid+1])
                return mid;
            else
                end = mid + 1;
        }
        return st;
    }
};