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

vv solve()
{
    int n = II, m = II, k = n * m + 1, x = -1, y = -1;
    vv v(n, vec(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int a = II;
            v[i][j] = k - a;
            if (a == k / 2)
                x = i, y = j;
        }
    
    if (n == 1 && m == 1)
        return {{-1}};
    
    if (k % 2)
        return v;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] != k / 2) {
                swap(v[i][j], v[x][y]);
                return v;
            }
    return {{-1}};
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pvv(solve());
    return 0;
}