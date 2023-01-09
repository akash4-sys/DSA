#include "headers.h"

class Solution
{
public:
    int xorBeauty(vector<int> &v)
    {
        int x = 0;
        for (auto n : v)
            x ^= n;
        return x;
    }
};