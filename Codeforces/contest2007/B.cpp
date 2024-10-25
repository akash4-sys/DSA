#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    ll n = LL, m = LL, x = 0, a;
    for (int i = 0; i < n; i++)
        a = LL, x = max(x, a);

    while (m--)
    {
        char c;
        cin >> c;
        ll l = LL, r = LL, val = c == '+' ? 1 : -1;
        if (l <= x && x <= r)
            x += val;
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}