#include "../../headers.h"

class Solution 
{
public:
    int singleNumber(vector<int>& v)
    {
        int ones = 0, twos = 0;
        for(int n: v)
        {
            ones = (ones ^ n) & (~twos);
            twos = (twos ^ n) & (~ones);
        }
        return ones;
    }
};