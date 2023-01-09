#include "headers.h"

#define ll long long
class Solution
{
    bool increased(vector<int> &v, ll power, ll minPowReq, int r, int k)
    {
        int n = v.size();
        vector<ll> add(v.size(), 0);
        for (int i = 0; i < n; i++)
        {
            if (i + r < n)
                power += v[i + r];
            if (power < minPowReq)
            {
                ll neededPow = minPowReq - power;
                if (neededPow > k)
                    return 0;
                k -= neededPow;
                power = minPowReq;
                add[min(n - 1, i + r)] += neededPow;
            }
            if (i - r >= 0)
                power -= (v[i - r] + add[i - r]);
        }
        return 1;
    }

public:
    ll maxPower(vector<int> &v, int range, int k)
    {
        ll r = accumulate(v.begin(), v.end(), 0LL) + k, ans, l = 0;
        ll power = accumulate(v.begin(), v.begin() + range, 0LL);
        while (l <= r)
        {
            ll mid = l + ((r - l) / 2);
            if (increased(v, power, mid, range, k))
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        return ans;
    }
};