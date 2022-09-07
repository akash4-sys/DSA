#include "../../headers.h"

class Solution
{
    vector<int> v;

public:
    Solution(vector<int> &nums) : v(nums) {}

    vector<int> reset()
    {
        return v;
    }

    vector<int> shuffle()
    {
        vector<int> ans(v);
        for (int i = 0; i < v.size(); i++)
        {
            int x = rand() % (ans.size() - i);
            swap(ans[i + x], ans[i]);
        }
        return ans;
    }
};