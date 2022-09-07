#include "../../headers.h"

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> v, ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
                v.push_back(i);
        }
        if (!v.size())
            return {-1, -1};
        return {v[0], v[v.size() - 1]};
    }
};

// Time Complexity - O(log n)
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lo == nums.size() || nums[lo] != target)
            return {-1, -1};
        int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {lo, hi};
    }
};