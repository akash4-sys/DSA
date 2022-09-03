#include "headers.h"

class Solution
{
public:
    bool findSubarrays(vector<int> &nums)
    {
        vector<int> sum;
        for (int i = 1; i < nums.size(); i++)
        {
            int x = nums[i] + nums[i - 1];
            if(find(sum.begin(), sum.end(), x) != sum.end())
                return true;
            sum.push_back(x);
        }
        return false;
    }
};