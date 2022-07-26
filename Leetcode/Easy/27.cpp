#include "../../headers.h"

class Solution
{
public:
    int removeElement(vector<int> &nums, int t)
    {
        int st = 0, end = nums.size() - 1;
        while (st <= end)
        {
            if (nums[st] == t && nums[end] == t)
            {
                end--;
                continue;
            }
            if (nums[st] == t && nums[end] != t)
            {
                nums[st] += nums[end];
                nums[end] = nums[st] - nums[end];
                nums[st] -= nums[end];
            }
            st++;
        }
        return st;
    }
};