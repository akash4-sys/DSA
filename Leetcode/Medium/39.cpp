#include "../../headers.h"

class Solution
{
    vector<vector<int>> ans;
    vector<int> curr;
public:
    vector<vector<int>> combinationSum(vector<int> &nums, int t, int i = 0, int sum = 0)
    {
        if(i >= nums.size() || sum > t) 
            return {{}};
        if(t == sum)
        {
            ans.push_back(curr);
            return ans;
        }
        curr.push_back(nums[i]);
        combinationSum(nums, t, i, sum + nums[i]);
        curr.pop_back();
        combinationSum(nums, t, i + 1, sum);
        return ans;
    }
};