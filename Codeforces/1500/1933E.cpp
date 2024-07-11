#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

void solve()
{
    int n = II;
    vector<ll> v(n + 1), pf(n + 1, 0);
    for (int i = 1; i <= n; i++)
        v[i] = II, pf[i] = pf[i - 1] + v[i];
    
    auto calc = [&](int l, int r, int u) {
        if (r < l || r > n)
            return 0LL;
        ll m = pf[r] - pf[l - 1];
        return (u * m) - ((m * (m - 1)) / 2);
    };
    
    for (int q = II; q--;)
    {
        ll l = II, u = II, low = l, high = n, score = 0, r = n + 1;
        while (low <= high)
        {
            ll k = (low + high) / 2;
            ll curr = calc(l, k, u), prev = calc(l, k - 1, u), next = calc(l, k + 1, u);
            if (curr >= prev && curr >= next)
                r = min(r, k);
            
            if (curr > prev)
                low = k + 1;
            else
                high = k - 1;
        }
        if (r == n + 1)
            r = l;
        cout << r << " ";
    }
    cout << "\n";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}