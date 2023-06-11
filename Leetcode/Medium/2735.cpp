#include "headers.h"

class Solution
{
public:
    long long minCost(vector<int> &v, int x)
    {
        using ll = long long;
        ll ans = LLONG_MAX, n = v.size();
        vector<ll> minv(n, LLONG_MAX);
        for (ll r = 0; r < n; r++)
        {
            ll sum = r * x;
            for (int i = 0; i < n; i++)
                minv[i] = min(minv[i], (ll)v[(i + r) % n]), sum += minv[i];
            ans = min(ans, sum);
        }
        return ans;
    }
};