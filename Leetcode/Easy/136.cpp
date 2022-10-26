#include "../../headers.h"

class Solution 
{
public:
    int singleNumber(vector<int>& v) 
    {
        int x = 0;
        for(int n : v)
            x ^= n;
        return x;
        // return accumulate(v.begin(), v.end(), 0, bit_xor<int>());
    }
};