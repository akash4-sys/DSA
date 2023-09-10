#include "../../headers.h"

class Solution
{
public:
    int numberOfPoints(vector<vector<int>> &v)
    {
        vector<int> nums(101, 0);
        for (auto &n : v)
            for (int i = n[0]; i <= n[1]; i++)
                nums[i] = 1;
        return count(nums.begin(), nums.end(), 1);
    }
};