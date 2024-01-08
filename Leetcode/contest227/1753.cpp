#include "../../headers.h"

class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        int k = v[2] - v[1];
        v[1] += min(k, v[0]);
        v[0] -= min(k, v[0]);
        return v[1] + (v[0] / 2);
    }
};