#include "headers.h"

class Solution
{
public:
    int minimizeSum(vector<int> &v)
    {
        sort(v.begin(), v.end());
        return min({v.back() - v[2], v[v.size() - 3] - v[0], v[v.size() - 2] - v[1]});
    }
};