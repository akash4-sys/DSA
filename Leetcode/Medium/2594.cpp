#include "headers.h"

#define ll long long
class Solution
{
public:
    long long repairCars(vector<int> &v, int c)
    {
        ll l = 1, r = 1LL * c * c * 100;
        while (l < r)
        {
            ll mid = l + ((r - l) / 2), curr = 0;
            for (int n : v)
                curr += sqrt(mid / n);
            if (curr >= c)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};