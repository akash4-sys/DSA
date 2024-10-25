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

bool solve()
{
    int n = II, m = II, q = II;
    vec a(n), b(m), v(n + 1, 0);
    iv(a);
    iv(b);
    for (int i = 0, j = 0; i < m; i++)
        if (j < n && b[i] == a[j])
            v[a[j]]++, j++;
        else if (!v[b[i]])
            return 0;
    return 1;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl((solve() ? "YA" : "TIDAK"));
    return 0;
}