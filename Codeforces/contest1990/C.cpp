#include <bits/stdc++.h>

using namespace std;

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

ll solve()
{
    ll n = II, moves = 2, ans = 0;
    vec v(n);
    iv(v);

    while (moves--)
    {
        ll x = 0;
        map<ll, int> mp;
        for (ll &a : v) {
            ans += a;
            mp[a]++;
            if (mp[a] >= 2)
                x = max(a, x);
            a = x;
        }
    }

    ll sum = accumulate(all(v), 0LL);
    for (int i = n - 1; i >= 0; i--)
        ans += sum, sum -= v[i];
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}