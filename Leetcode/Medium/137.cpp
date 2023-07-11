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

class Solution 
{
public:
    int singleNumber(vector<int>& v)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int cnt = 0;
            for(int n : v)
                cnt += ((n & (1 << i)) != 0);
            ans = (cnt % 3) ? ans | (1 << i) : ans;
        }
        return ans;
    }
};