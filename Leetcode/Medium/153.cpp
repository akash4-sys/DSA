#include "../../headers.h"

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.size() == 1 || nums[0] < nums[nums.size() - 1])
            return nums[0];

        int st = 0, end = nums.size() - 1, ans = 0;
        while (st <= end)
        {
            int mid = (st + end) / 2;

            if(nums[mid] > nums[mid + 1])
                return nums[mid+1];

            if(nums[mid - 1] > nums[mid])
                return nums[mid];
            
            if(nums[mid] > nums[0])
                st = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};