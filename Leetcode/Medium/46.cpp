#include "../../headers.h"

class Solution
{
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int> nums, int st = 0)
    {
        if (st == nums.size())
            ans.push_back(nums);
        else
            for (int i = st; i < nums.size(); i++)
            {
                swap(nums[i], nums[st]);
                permute(nums, st + 1);
            }
        return ans;
    }
};


// Faster than above
class Solution
{
    vector<vector<int>> ans;
    vector<int> perm, freq;
    void recurse(vector<int> &nums)
    {
        if(perm.size() == nums.size())
        {
            ans.push_back(perm);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(freq[i])
                continue;
            perm.push_back(nums[i]);
            freq[i] = 1;
            recurse(nums);
            freq[i] = 0;
            perm.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        freq = vector<int>(nums.size(), 0);
        recurse(nums);
        return ans;
    }
};