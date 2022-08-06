#include "../../headers.h"

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() - s.count(0);
    }
};