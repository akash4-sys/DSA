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
    int n = II, m = II;
    vv ans;
    vector<string> v(n);
    iv(v);
    
    if (v[0][0] == '1') {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == '1')
            {
                int res = 0;
                if (j && v[i][j - 1] == '0')
                    res = 1, ans.push_back({i + 1, j, i + 1, j + 1});
                else if (i && v[i - 1][j] == '0')
                    res = 1, ans.push_back({i, j + 1, i + 1, j + 1});
                if (!res) {
                    cout << "-1\n";
                    return;
                }
                v[i][j] = '0';
            }
    
    cout << ans.size() << "\n";
    reverse(all(ans));
    for (auto &r : ans)
        pv(r);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}