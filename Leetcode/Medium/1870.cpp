#include "../../headers.h"

class Solution
{
    bool canReach(vector<int> &v, double time, int speed)
    {
        double t = 0;
        for (int i = 0; i < v.size(); i++)
        {
            t = ceil(t);
            t += (double)v[i] / speed;
            if (t > time)
                return 0;
        }
        return 1;
    }

public:
    int minSpeedOnTime(vector<int> &v, double time)
    {
        int l = 1, r = 1e7;
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            if (canReach(v, time, mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l > 1e7 ? -1 : l;
    }
};

