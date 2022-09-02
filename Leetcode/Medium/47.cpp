#include "../../headers.h"

class Solution
{
    vector<vector<int>> ans;
    void permute(vector<int> nums, int st)
    {
        if (st == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = st; i < nums.size(); i++)
        {
            if(i != st && nums[i] == nums[st])
                continue;
            swap(nums[i], nums[st]);
            permute(nums, st + 1);
        }
        return;
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        permute(nums, 0);
        return ans;
    }
};