#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define iv(v) { for(auto &x : v) cin >> x; }

ll solve()
{
    int n = II, l = 0, r = n - 1;
    vec v(n);
    iv(v);
    sort(all(v));

    ll sum = 0, ans = 0;
    while (l < r)
    {
        sum += v[l];
        if (sum >= v[r]) {
            v[l] = sum - v[r];
            ans += v[r] + 1;
            sum = 0;
            v[r--] = 0;
        }
        else
            v[l++] = 0;
    }

    if (l == r)
    {
        if (sum >= v[r] && sum) {
            ans += v[r] + 1;
            sum -= v[r];
            v[r] = 0;
        }
        int cnt = sum + ((v[r] - sum) / 2);
        ans += cnt + (cnt > 0) + ((v[r] - sum) % 2);
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}