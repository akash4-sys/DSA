#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<int>
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

ll solve()
{
    int n = II, x = II;
    vec v(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ll a = LL;
        if (a <= n)
            v[a]++;
    }

    for (int a = 0; a <= n; a++) {
        if (!v[a])
            return a;
        for (int j = 1; j < v[a]; j++)
            if (a + (x * j) <= n)
                v[a + (x * j)]++;
            else
                break;
    }
    return n + 1;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}