#include "headers.h"

class Solution
{
public:
    int minimizeSum(vector<int> &v)
    {
        sort(v.begin(), v.end());
        int n = v.size(), x = v.back() - v[2], y = v[n - 3] - v[0], z = v[n - 2] - v[1];
        return min({x, y, z});
    }
};