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

ll query(int type, int l, int r) {
    cout << type << " " << l << " " << r << endl;
    cout.flush();
    ll sum = LL;
    return sum;
}

void print(int l, int r) {
    cout << "! " << l << " " << r << endl;
    cout.flush();
}

void solve()
{
    ll n = II, l = 1, r = n, total = n * (n + 1) / 2;
    ll len = query(2, 1, n) - total;
    while (l <= r)
    {
        int k = (l + r) / 2;
        ll x = query(1, 1, k), y = query(2, 1, k);
        if (x >= y)
            l = k + 1;
        else
            r = k - 1;
    }
    print(l, l + len - 1);
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}