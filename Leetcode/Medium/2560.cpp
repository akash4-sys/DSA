#include "headers.h"

class Solution
{
public:
    int minCapability(vector<int> &v, int k)
    {
        int l = INT_MAX, r = INT_MIN;
        for (int n : v)
            l = min(l, n), r = max(r, n);
        while (l < r)
        {
            int cap = l + ((r - l) / 2), c = 0;
            for (int i = 0; i < v.size(); i++)
                if (v[i] <= cap)
                    c++, i++;
            if (c >= k)
                r = cap;
            else
                l = cap + 1;
        }
        return l;
    }
};