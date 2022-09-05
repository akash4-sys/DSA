#include "../../headers.h"

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &v, int k)
    {
        if (k <= 1) 
            return 0;
        int ans = v.size(), l = 0, mul = 1;
        for(int i = 0; i < v.size(); i++)
        {
            mul *= v[i];
            while(mul >= k)
                mul /= v[l++];
            ans += i - l + 1;
        }
        return ans;
    }
};