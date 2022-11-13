#include "headers.h"

// One way of checking all subarrays except empty
// Here ans is count of suibarrys with lcm k
class Solution
{
public:
    int subarrayLCM(vector<int> &v, int k)
    {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
            for (long long int j = i, l = v[i]; j < v.size() && l < k; j++)
                l = lcm(l, v[j]), ans += (l == k);
        return ans;
    }
};