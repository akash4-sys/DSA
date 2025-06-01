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

vec gen(string &s, string &x)
{
    char p = s[0];
    int cnt = 0;
    vec a;
    for (char &c : s) {
        if (c != p) {
            a.push_back(cnt);
            cnt = 0;
            p = c;
            x += p;
        }
        cnt++;
    }
    x += p;
    a.push_back(cnt);
    return a;
}

bool solve()
{
    string s = SS, r = SS, x, y;
    vec a = gen(s, x), b = gen(r, y);
    if (a.size() != b.size() || x != y)
        return 0;
    
    for (int i = 0; i < a.size(); i++) {
        if (x[i] != y[i])
            return 0;
        if (!(b[i] >= a[i] && b[i] <= a[i] * 2))
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