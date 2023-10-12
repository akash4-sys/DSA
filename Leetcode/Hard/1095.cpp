#include "../../headers.h"

class Solution
{
    int findPeak(MountainArray &m, int n)
    {
        int l = 0, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            m.get(mid) < m.get(mid + 1) ? l = mid + 1 : r = mid;
        }
        return l;
    }

    int binary_search(MountainArray &m, int l, int r, int t, int inc = 1)
    {
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (m.get(mid) == t)
                return mid;
            if (inc)
                m.get(mid) < t ? l = mid + 1 : r = mid - 1;
            else
                m.get(mid) < t ? r = mid - 1 : l = mid + 1;
        }
        return -1;
    }

public:
    int findInMountainArray(int t, MountainArray &m)
    {
        int n = m.length(), p = findPeak(m, n - 1);
        int ans = binary_search(m, 0, p, t);
        return ans != -1 ? ans : binary_search(m, p + 1, n - 1, t, 0);
    }
};