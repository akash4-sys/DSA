#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

ll solve()
{
    ll n = II, k = II, x = 0;
    map<ll, ll> mp;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
        ll a = II, r = a % k;
        if (r) {
            ll p = k - r + (mp[r] * k);
            pq.push(p);
            mp[r]++;
        }
    }

    while (!pq.empty()) {
        ll a = pq.top();
        pq.pop();
        if (a < x)
            a += k, pq.push(a);
        else
            x += (a - x), x++;
    }
    return x;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}