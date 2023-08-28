#include "headers.h"

class Solution
{
public:
    long long maxArrayValue(vector<int> &nums)
    {
        vector<long long> v;
        for (int n : nums)
            v.push_back(n);
        for (int i = v.size() - 2; i >= 0; i--)
            if (v[i] <= v[i + 1])
                v[i] += v[i + 1];
        return  *max_element(v.begin(), v.end());
    }
};