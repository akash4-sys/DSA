#include "../../headers.h"

class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v = nums;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
            if (v[i] != nums[i])
            {
                int j = i + 1;
                for (; j < n && nums[j] != v[i] && __builtin_popcount(nums[j]) == __builtin_popcount(nums[i]); j++);
                if (j < n && v[i] == nums[j] && __builtin_popcount(nums[j]) == __builtin_popcount(nums[i]))
                    swap(nums[j], nums[i]);
            }
        return v == nums;
    }
};