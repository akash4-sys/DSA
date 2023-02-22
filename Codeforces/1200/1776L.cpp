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
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v, n) { for(int i = 0; i < n; i++) cin >> v[i]; }

void solve()
{
    ll n = LL;
    string s = SS;
    ll q = LL, p = 0, m = 0;
    for (char &c : s)
        p += c == '+', m += c == '-';

    while (q--)
    {
        ll x = LL, y = LL, t = (p - m) * y;
        if (x == y)
            cout<<(t ? "no" : "yes")<<endl;
        else
        {
            ll v = t / (y - x);
            if (t != v * (y - x))
                pl("no");
            else if ((t && v >= -m && v <= p) || !t)
                pl("yes");
            else
                pl("no");
        }
    }
}

int main()
{
    fast;
    solve();
    return 0;
}