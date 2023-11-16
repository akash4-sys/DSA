#include "../../headers.h"

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &v)
    {
        sort(v.begin(), v.end());
        v[0] = 1;
        for (int i = 1; i < v.size(); i++)
            if (v[i] - v[i - 1] > 1)
                v[i] = v[i - 1] + 1;
        return v.back();
    }
};