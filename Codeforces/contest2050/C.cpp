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

ll f(ll m, ll two, ll three) {
    if (m % 2)
        return 0;
    if (m / 2 <= two || m == 0)
        return 1;
    m -= min(m / 6, three) * 6;
    return m / 2 <= two;
}

ll solve()
{
    string s = SS;
    ll sum = 0, two = 0, three = 0;
    for (char &c : s)
        sum += (c - '0'), two += c == '2', three += c == '3';
    
    ll m = (9 - (sum % 9)) % 9;
    if (f(m, two, three))
        return 1;
    if (f(m + 9, two, three))
        return 1;
    if (f(m + 18, two, three))
        return 1;
    return 0;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pyn(solve());
    return 0;
}