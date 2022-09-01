#include "../../headers.h"

class Solution
{
    vector<vector<int>> ans;
    vector<int> sub;
    void recurse(vector<int> &nums, int st)
    {
        ans.push_back(sub);
        for(int i = st; i < nums.size(); i++)
        {
            if(i > st && nums[i] == nums[i - 1])
                continue;
            sub.push_back(nums[i]);
            recurse(nums, i + 1);
            sub.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        recurse(nums, 0);
        return ans;
    }
};