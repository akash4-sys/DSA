#include "headers.h"

class Solution
{
public:
    int buyChoco(vector<int> &v, int m)
    {
        sort(v.begin(), v.end());
        int x = m - (v[0] + v[1]);
        return x < 0 ? m : x;
    }
};