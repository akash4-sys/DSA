#include "headers.h"

class Solution
{
public:
    int minimizeMax(vector<int> &v, int p)
    {
        sort(v.begin(), v.end());
        int n = v.size(), l = 0, r = v[n - 1] - v[0];
        while (l < r)
        {
            int mid = (l + r) / 2, k = 0;
            for (int i = 1; i < n && k < p; i++)
                if (v[i] - v[i - 1] <= mid)
                    k++, i++;
            if (k >= p)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};