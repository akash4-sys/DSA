#include "../../headers.h"

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        if (n == 0)
            return 0;

        vector<int> v = {0, 1};
        int maxi = 0;
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
                v.push_back(v[i / 2]);
            else
                v.push_back(v[(i - 1) / 2] + v[(i - 1) / 2 + 1]);
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }
};