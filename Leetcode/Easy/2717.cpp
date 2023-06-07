#include "headers.h"

class Solution
{
public:
    int semiOrderedPermutation(vector<int> &v)
    {
        int ans = 0, x = 0, y = 0, z = 0;
        for (int i = 0; i < v.size(); i++)
            if (v[i] == 1)
                x = i;
            else if (v[i] == v.size())
                y = v.size() - i - 1,  z = i;
        ans += x + y;
        ans -= z < x;
        return ans;
    }
};