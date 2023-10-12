#include "../../headers.h"

class Solution
{
    bool possible(vector<int> &v, int k)
    {
        for (int i = 0; i < k; i++)
            if (v[i] >= v[v.size() - k + i])
                return 0;
        return 1;
    }

public:
    int minLengthAfterRemovals(vector<int> &v)
    {
        int l = 0, r = v.size() / 2, p = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (possible(v, mid))
                l = mid + 1, p = mid;
            else
                r = mid - 1;
        }
        return v.size() - (l * 2);
    }
};