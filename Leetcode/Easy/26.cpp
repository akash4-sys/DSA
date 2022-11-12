#include "../../headers.h"

class Solution
{
public:
    int removeDuplicates(vector<int> &v, int j = 0)
    {
        for (int i = 1; i < v.size(); i++)
            if (v[i] != v[i - 1])
                v[j++] = v[i - 1];
        v[j++] = v.back();
        return j;
    }
};


// STL APPROACH:
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        auto it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));
        return nums.size();
    }
};