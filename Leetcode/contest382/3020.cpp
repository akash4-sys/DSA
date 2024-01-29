#include "../../headers.h"

#define ll long long
class Solution
{
public:
    int maximumLength(vector<int>& v)
    {
        unordered_map<ll, ll> mp;
        for (int a : v)
            mp[a]++;
        
        ll ans = mp[1] % 2 == 0 ? mp[1] - 1 : mp[1];
        for (int a : v)
        {
            if (a == 1)
                continue;
            ll x = a, len = 0;
            while (mp.count(x) && mp[x] >= 2)
                len += 2, x *= x;
            len += (mp.count(x) && mp[x] == 1) ? 1 : -1;
            ans = max(ans, len);
        }
        return ans;
    }
};