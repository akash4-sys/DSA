#include "../../headers.h"

class Solution
{
public:
    int maximumEnergy(vector<int> &v, int k)
    {
        int ans = INT_MIN, n = v.size();
        for (int i = n - 1; i >= 0; i--)
            if (i + k < n)
                v[i] += v[i + k];
        return *max_element(v.begin(), v.end());
    }
};