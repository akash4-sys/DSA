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
    int n = II, m = II;
    vec a(m);
    iv(a);
    sort(all(a));

    for (int l = 0, r = m - 1, k = n; k > 0; k -= 2, l++, r--)
    {
        for (int i = 0; i < 3; i++)
            cout << a[l] << " " << a[r] << " ";
        cout << "\n";
        if (k > 1) {
            for (int i = 0; i < 3; i++)
                cout << a[r] << " " << a[l] << " ";
            cout << "\n";
        }
    }
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}