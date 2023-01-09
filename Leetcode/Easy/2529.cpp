#include "headers.h"

class Solution
{
public:
    int maximumCount(vector<int> &v)
    {
        int pos = 0, neg = 0;
        for (int n : v)
            pos += (n > 0), neg += (n < 0);
        return max(pos, neg);
    }
};