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
    ll n = LL, mod = LL, mul = 1;
    vec v(n), ans;
    iv(v);
    string s = SS;
    reverse(all(s));

    int l = count(all(s), 'L'), r = n - count(all(s), 'R') - 1;
    for (char &c : s)
    {
        if (c == 'L')
            mul = (mul * v[--l]) % mod;
        else
            mul = (mul * v[++r]) % mod;
        ans.push_back(mul);
    }
    
    reverse(all(ans));
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