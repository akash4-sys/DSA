#include "../../headers.h"

class Solution
{
public:
    int singleNonDuplicate(vector<int> &v)
    {
        int l = 0, r = v.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if ((mid % 2 == 0 && v[mid] == v[mid + 1]) || (mid % 2 && v[mid] == v[mid - 1]))
                l = mid + 1;
            else
                r = mid;
        }
        return v[r];
    }
};