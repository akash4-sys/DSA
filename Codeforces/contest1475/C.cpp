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
    int A = II, B = II, k = II;
    vec boys(k), girls(k);
    iv(boys);
    iv(girls);

    ll ans = 0;
    map<int, int> b, g;
    for (int &x : boys)
        b[x]++;
    for (int &x : girls)
        g[x]++;
    
    for (int i = 0; i < k; i++) {
        ans += (k - b[boys[i]] - g[girls[i]]);
        if (b[boys[i]] > 0 && g[girls[i]] > 0)
            ans++;
    }
    return ans / 2;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}