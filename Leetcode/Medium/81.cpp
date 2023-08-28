#include "../../headers.h"

class Solution
{
public:
    bool search(vector<int> &v, int t)
    {
        for (int l = 0, r = v.size() - 1; l < r; )
        {
            int mid = (l + r) / 2;
            if (v[mid] == t)
                return 1;
            if (v[l] == v[mid] && v[r] == v[mid])
                l++, r--;
            else if (v[l] <= v[mid])
                (v[l] <= t && v[mid] > t) ? r = mid - 1 : l = mid + 1;
            else
                (v[mid] < t && v[r] >= t) ? l = mid + 1 : r = mid - 1;
        }
        return 0;
    }
};