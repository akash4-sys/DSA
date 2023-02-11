#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(vv) { for(auto &v : vv) pv(v), br; }
#define iv(v, n) { for(int i = 0; i < n; i++) cin >> v[i]; }

ll solve()
{
    ll n = LL, K = LL, ans = 0, k = 2 * K;
    vector<ll> v(n);
    iv(v, n);
    sort(all(v));
    for (int i = 0; i < n;)
    {
        if (k < v[i])
        {
            v[i] -= k;
            k = 2 * K;
            ans++;
        }
        else if (k >= v[i])
        {
            k -= v[i];
            v[i] = 0;
            if ((k < K || !k) && i != n - 1)
                ans++, k = 2 * K;
            else
                k = K;
            i++;
        }
    }
    return ans + 1;
}

int main()
{
    fast;
    pl(solve());
    return 0;
}