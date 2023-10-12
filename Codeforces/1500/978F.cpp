#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

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
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) { for(auto &x : v) pf(x); }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

vec solve()
{
    int n = II, k = II;
    vec a(n);
    iv(a);

    vv v(n), qr(n);
    for (int i = 0; i < n; i++)
        v[i] = {a[i], i};

    for (int i = 0; i < k; i++)
    {
        int x = II - 1, y = II - 1;
        qr[x].push_back(y);
        qr[y].push_back(x);
    }

    sort(all(v));
    vec ans(n);
    unordered_map<int, int> pg, r;
    for (int i = 0; i < n; i++)
    {
        int cnt = (i - r[v[i][0]]);
        for (int p : qr[v[i][1]])
            cnt -= (pg.count(p) && a[p] != v[i][0]);
        ans[v[i][1]] = max(cnt, 0);
        r[v[i][0]]++;
        pg[v[i][1]]++;
    }
    return ans;
}

int main()
{
    fast;
    pv(solve());
    return 0;
}