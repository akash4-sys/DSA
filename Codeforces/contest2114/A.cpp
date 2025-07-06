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
    string s = SS;
    int n = stoi(s);
    for (int a = 0; a <= 100; a++)
        for (int b = 0; b <= 100; b++)
            if ((a + b) * (a + b) == n) {
                cout << a << " " << b << endl;
                return;
            }
    cout << -1 << endl;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}