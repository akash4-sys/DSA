#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<int>
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

void solve()
{
    int n = II;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[II]++;
    
    vector<int> df(n + 2, 0);
    for (int i = 0; i <= n; i++) {
        df[mp[i]]++;
        df[n - i + 1]--;
        if (!mp[i])
            break;
    }

    int p = 0;
    for (int k = 0; k <= n; k++) {
        int res = (k ? p : 0) + df[k];
        pf(res);
        p = res;
    }
    br;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}