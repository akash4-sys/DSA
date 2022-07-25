#include "../../headers.h"

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == nums[i + 1])
            {
                nums.erase(nums.begin() + i);
                continue;
            }
            i++;
        }
        return nums.size();
    }
};

// STL APPROACH:
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        vector<int>::iterator it;
        it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));
        return nums.size();
    }
};