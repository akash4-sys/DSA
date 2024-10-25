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
#define pyn(x) cout << (x ? "Yes" : "No") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

bool solve()
{
    int n = II, i = 0;
    string s = SS;
    while (i < n && s[i] == '1')
        i++;    
    if (i == n)
        return n == 4;
    return (i - 1) * (i - 1) == n;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pyn(solve());
    return 0;
}