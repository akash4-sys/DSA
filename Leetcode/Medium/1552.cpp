#include "../../headers.h"

class Solution
{
    bool arrange(vector<int> &v, int k, int &d)
    {
        for (int i = 1, prev = v[0]; i < v.size(); i++)
            if (v[i] - prev >= d)
            {
                k--;
                prev = v[i];
                if (k <= 0)
                    return true;
            }
        return false;
    }

public:
    int maxDistance(vector<int> &v, int k)
    {
        sort(v.begin(), v.end());
        int l = 1, h = v.back(), ans;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (arrange(v, k - 1, mid))
                ans = mid, l = mid + 1;
            else
                h = mid - 1;
        }
        return ans;
    }
};