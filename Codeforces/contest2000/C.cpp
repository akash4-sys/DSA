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
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

bool query(int n, vec &a)
{
    string s = SS;
    if (s.size() != n)
        return 0;

    vec ch(26, INT_MAX);
    map<int, char> mp;
    for (int i = 0; i < n; i++)
    {
        if (ch[s[i] - 'a'] != INT_MAX && ch[s[i] - 'a'] != a[i])
            return 0;
        if (mp.count(a[i]) && mp[a[i]] != s[i])
            return 0;
        ch[s[i] - 'a'] = a[i];
        mp[a[i]] = s[i];
    }
    return 1;
}

void solve()
{
    int n = II;
    vec a(n);
    iv(a);

    int m = II;
    while (m--)
        pl((query(n, a) ? "YES" : "NO"));
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}