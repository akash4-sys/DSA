#include "../../headers.h"

class Solution
{
public:
    long long minimumTime(vector<int>& v, int k)
    {
        long long l = 0, r = LLONG_MAX / v.size();
        while (l < r)
        {
            long long mid = l + ((r - l) / 2), time = 0;
            for (int &n : v)
                time += (mid / n);
            if (time >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};