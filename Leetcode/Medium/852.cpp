#include "../../headers.h"

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &v)
    {
        int l = 0, r = v.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (v[mid] < v[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};