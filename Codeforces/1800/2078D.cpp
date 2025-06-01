#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define CC ({ char s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

ll solve()
{
    int n = II, anext = n - 1, bnext = n - 1;
    vector<vector<int>> a, b;
    for (int i = 0, x1, x2; i < n; i++) {
        char c1, c2;
        cin >> c1 >> x1 >> c2 >> x2;
        a.push_back({x1, c1 == 'x'});
        b.push_back({x2, c2 == 'x'});
    }

    vector<int> pos(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        if (!a[i][1] && !b[i][1])
            pos[i] = pos[i + 1];
        else if (a[i][1] && !b[i][1])
            pos[i] = 0;
        else if (!a[i][1] && b[i][1])
            pos[i] = 1;
        else if (a[i][0] > b[i][0])
            pos[i] = 0;
        else if (a[i][0] < b[i][0])
            pos[i] = 1;
        else
            pos[i] = pos[i + 1];
    }

    vector<long long> ans(2, 1);
    for (int i = 0; i < n; i++)
    {
        ll x = a[i][1] ? ans[0] * (a[i][0] - 1) : a[i][0];
        x += b[i][1] ? ans[1] * (b[i][0] - 1) : b[i][0];
        ans[pos[i + 1]] += x;
    }
    return ans[0] + ans[1];
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}