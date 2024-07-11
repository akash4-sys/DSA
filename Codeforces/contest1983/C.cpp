#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

void solve()
{
    int n = LL;
    vv v(3, vec(n));
    for (auto &r : v) {
        ll sum = 0;
        for (ll &a : r)
            sum += LL, a = sum;
    }
    
    ll m = ceil(v[0][n - 1] / 3.0);
    vec res;
    function<bool(int, int, vec)> rec = [&](int i, int mask, vec idx) -> bool {
        if (mask == 0) {
            if (res.empty())
                res = idx;
            return 1;
        }
        if (i == n)
            return 0;
        
        for (int k = 0; k < 3; k++)
            if (mask & (1 << k))
            {
                ll extra = i ? v[k][i - 1] : 0;
                int j = lower_bound(all(v[k]), m + extra) - v[k].begin();
                if (j == n)
                    continue;

                idx[k] = j;
                if (rec(j + 1, mask ^ (1 << k), idx))
                    return 1;
                idx[k] = -1;
            }
        return 0;
    };

    if (!rec(0, 7, {-1, -1, -1})) {
        cout << "-1\n";
        return;
    }

    vv idx, ans(3);
    for (int i = 0; i < 3; i++)
        idx.push_back({res[i], i});
    sort(all(idx));

    idx[2][0] = n - 1;
    for (int i = 0, prev = 1; i < 3; i++)
        ans[idx[i][1]] = {prev, idx[i][0] + 1}, prev = idx[i][0] + 2;
    
    for (auto &p : ans)
        cout << p[0] << " " << p[1] << " ";
    cout << "\n";
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        solve();
    return 0;
}