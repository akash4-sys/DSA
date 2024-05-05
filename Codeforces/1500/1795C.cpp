

#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define pf(x) cout << x << " "
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define iv(v) { for(auto &x : v) cin >> x; }

// Tough Implementation

void solve()
{
    ll n = LL, k = 0, cnt = 0;
    vec a(n), b(n), c(n + 1, 0), ans(n + 1, 0), pf_sum = {0};
    iv(a);
    iv(b);

    for (ll &x : b)
        pf_sum.push_back(pf_sum.back() + x);
    
    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(all(pf_sum), a[i] + pf_sum[i]) - pf_sum.begin() - 1;
        c[i]++, c[j]--;
        ans[j] += a[i] - pf_sum[j] + pf_sum[i];
    }

    for (int i = 0; i < n; i++) {
        cnt += c[i];
        pf(cnt * b[i] + ans[i]);
    }
    br;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}