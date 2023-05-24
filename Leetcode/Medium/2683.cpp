#include "headers.h"

class Solution
{
public:
    bool doesValidArrayExist(vector<int> &v)
    {
        int ans = 0;
        for (int n : v)
            ans ^= n;
        return !ans;
    }
};