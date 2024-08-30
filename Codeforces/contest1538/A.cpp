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

int solve()
{
    int n = II, x = 0, y = n;
    vec v(n);
    for (int i = 0; i < n; i++)
        v[i] = II, x = max(x, v[i]), y = min(y, v[i]);
    
    int i, j;
    for (int k = 0; k < n; k++)
        if (v[k] == x)
            i = k + 1;
        else if (v[k] == y)
            j = k + 1;
    
    if (i > j) swap(i, j);
    return min({max(i, j), max(n - i + 1, n - j + 1), i + (n - j + 1)});
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}