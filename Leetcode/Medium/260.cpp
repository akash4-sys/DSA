#include "../../headers.h"

// A little slow coz of accumulate
class Solution 
{
public:
    vector<int> singleNumber(vector<int>& v) 
    {
        vector<int> ans = {0, 0};
        long x = accumulate(v.begin(), v.end(), 0, bit_xor<long>());
        x &= -x;
        for(int n: v)
            ans[!(n & x)] ^= n;
        return ans;
    }
};


class Solution
{
public:
    vector<int> singleNumber(vector<int>& v) 
    {
        long x = 0;
        vector<int> ans = {0, 0};
        for(int n: v)
            x ^= n;
        
        x &= -x;        // return last set one bit
        for(int n: v)
            if((n & x) == 0)
                ans[0] ^= n;
            else
                ans[1] ^= n;
        return ans;
    }
};