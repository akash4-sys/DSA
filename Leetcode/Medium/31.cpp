#include "../../headers.h"

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int N = nums.size(), i = N - 1;
        while (i - 1 >= 0 && nums[i - 1] >= nums[i])
            --i;
        int st = i, en = N - 1;
        while (st < en)
        {
            nums[st] += nums[en];
            nums[en] = nums[st] - nums[en];
            nums[st] -= nums[en];
            st++;
            en--;
        }
        if (i - 1 >= 0)
            swap(*upper_bound(begin(nums) + i, end(nums), nums[i - 1]), nums[i - 1]);
    }
};