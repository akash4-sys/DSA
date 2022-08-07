#include "headers.h"

// duplicates can be removed

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(j - i != nums[j] - nums[i])
                    count++;
            }
        }
        return count;
    }
};