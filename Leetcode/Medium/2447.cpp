#include "../../headers.h"

class Solution
{
public:
    int subarrayGCD(vector<int> &v, int k)
    {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
            for (int j = i, x = v[i]; j < v.size() && v[j] % k == 0; j++)
            {
                x = gcd(x, v[j]);
                ans += x == k;
            }
        return ans;
    }
};