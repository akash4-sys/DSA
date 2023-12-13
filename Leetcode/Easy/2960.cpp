#include "../../headers.h"

class Solution
{
public:
    int countTestedDevices(vector<int> &v)
    {
        int ans = 0, sub = 0;
        for (int i = 0; i < v.size(); i++)
            if (v[i] - sub > 0)
                ans++, sub++;
        return ans;
    }
};