#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

vec solve()
{
    ll n = LL;
    vec pfsum(n + 1, 0), ans;
    for (int i = 1; i <= n; i++)
        pfsum[i] += pfsum[i - 1] + LL;
    
    auto nsum = [](ll x){ return x * (x + 1) / 2; };
    ll q = LL;
    for (int i = 0; i < q; i++)
    {
        ll L = LL, u = LL, r = n, l = L, res = L;
        ll s = (pfsum[L] - pfsum[L - 1]), best = s * u - nsum(s - 1);
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            ll a = pfsum[mid] - pfsum[L - 1], curr = a * u - nsum(a - 1);
            if (curr >= best)
            {
                if (curr == best)
                    res = min(res, mid);
                else
                    res = mid;
                l = mid + 1, best = curr;
            }
            else
                r = mid - 1;
        }
        ans.push_back(res);
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}