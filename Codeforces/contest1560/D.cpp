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

ll lcs(string &s, string &r)
{
    ll i = 0;
    for (char &c : s)
        if (i < r.size() && c == r[i])
            i++;
    return i;
}

ll solve()
{
    string s = SS;
    ll m = s.size(), ans = m * 2 + 1;
    for (ll k = 0; k < 64; k++)
    {
        string r = to_string(1LL << k);
        ll len = lcs(s, r), missing = r.size() - len, extra = m - len;
        ans = min(ans, missing + extra);
    }
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