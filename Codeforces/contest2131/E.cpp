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
    int n = II;
    vec a(n), b(n), v(n + 1, 0);
    iv(a); iv(b);
    
    a.push_back(0);
    for (int i = n - 1; i >= 0; i--) {
        v[i] = a[i];
        if (a[i] == b[i])
            continue;
        if ((a[i] ^ v[i + 1]) == b[i])
            v[i] ^= v[i + 1];
        else if ((a[i] ^ a[i + 1]) == b[i])
            v[i] = a[i] ^ a[i + 1];
        else
            return 0;
    }
    return 1;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pyn(solve());
    return 0;
}