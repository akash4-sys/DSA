#include "../../headers.h"

class Solution
{
    vector<vector<int>> ans;
    vector<int> curr;
    void recurse(vector<int> &nums, int t, int st)
    {
        if (t == 0)
            ans.push_back(curr);
        if (t <= 0)
            return;
        int prev = -1;
        for(int i = st; i < nums.size(); i++)
        {
            if(nums[i] == prev)
                continue;
            curr.push_back(nums[i]);
            recurse(nums, t - nums[i], i + 1);
            curr.pop_back();
            prev = nums[i];
        }
        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &nums, int t)
    {
        sort(begin(nums), end(nums));
        recurse(nums, t, 0);
        return ans;
    }
};