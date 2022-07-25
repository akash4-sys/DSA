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
        return {v[0], v[v.size()-1]};
    }
};