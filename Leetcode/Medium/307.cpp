#include "../../headers.h"

class NumArray
{
public:
    int len;
    vector<int> sums, nums;

    NumArray(vector<int> &nums) : nums(nums)
    {
        if (nums.empty())
            return;
        len = ceil(sqrt(nums.size()));
        sums = vector<int>(ceil((double)nums.size() / len));
        for (int i = 0; i < nums.size(); ++i)
        {
            sums[i / len] += nums[i];
        }
    }

    void update(int i, int val)
    {
        sums[i / len] += val - nums[i];
        nums[i] = val;
    }

    int sumRange(int i, int j)
    {
        int sum = 0, start = i / len, end = j / len;
        if (start == end)
        {
            while (i <= j)
                sum += nums[i++];
        }
        else
        {
            for (int k = (start + 1) * len - 1; k >= i; --k)
                sum += nums[k];
            for (int k = start + 1; k < end; ++k)
                sum += sums[k];
            for (int k = end * len; k <= j; ++k)
                sum += nums[k];
        }
        return sum;
    }
};