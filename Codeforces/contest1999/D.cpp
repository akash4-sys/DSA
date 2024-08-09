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

void solve()
{
    string s = SS, t = SS;
    int i = 0;
    for (char &c : s)
    {
        if (i == t.size())
            break;
        if (c == t[i])
            i++;
        else if(c == '?')
            c = t[i], i++;
    }

    if (i != t.size()) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (char &c : s)
        if (c == '?')
            c = 'a';
    pl(s);
    return;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}