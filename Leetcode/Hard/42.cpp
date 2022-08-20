#include "../../headers.h"

class Solution
{
public:
    int trap(vector<int> &h)
    {
        int ans = 0, i = 0, j = h.size() - 1, lmax = 0, rmax = 0;
        while (i < j)
        {
            if (h[i] < h[j])
                (h[i] >= lmax) ? lmax = h[i] : ans += (lmax - h[i]), i++;
            else
                (h[j] >= rmax) ? rmax = h[j] : ans += (rmax - h[j]), j--;
        }
        return ans;
    }
};