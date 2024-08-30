#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<int>
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

bool solve()
{
    int n = II;
    vec a(n + 1), b(n + 2, 0);
    for (int i = 1; i <= n; i++)
        a[i] = II;
    
    b[a[1]] = 1;
    for (int i = 2; i <= n; i++)
        if (b[a[i] - 1] || b[a[i] + 1])
            b[a[i]] = 1;
        else
            return 0;
    return 1;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl((solve() ? "YES" : "NO"));
    return 0;
}