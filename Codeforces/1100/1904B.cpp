#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

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

// Time Complexity - O(NlogN)
// Space Complexity - O(N)

vec solve()
{
    ll n = LL, sum = 0;
    vv v(n);
    for (int i = 0; i < n; i++)
        v[i] = {LL, i}, sum += v[i][0];

    sort(all(v));
    vec ans(n, 0);
    ans[v[n - 1][1]] = n - 1;
    sum -= v[n - 1][0];
    for (int i = n - 2; i >= 0; i--)
    {
        if (sum >= v[i + 1][0])
            ans[v[i][1]] += ans[v[i + 1][1]] - i;
        ans[v[i][1]] += i;
        sum -= v[i][0];
    }
    return ans;
}


// Time Complexity - O(NlogN)
// Space Complexity - O(N)

vec solve2()
{
    ll n = LL;
    vv v(n);
    for (int i = 0; i < n; i++)
        v[i] = {LL, i};

    sort(all(v));
    vec prefix_sum(n, 0), ans(n, 0);
    for (int i = 0; i < n; i++)
        prefix_sum[i] = (i ? prefix_sum[i - 1] : 0) + v[i][0];
   
    for (int k = 0; k < n; k++)
    {
        ans[v[k][1]] = k;
        ll sum = prefix_sum[k], i = k;
        while (i + 1 < n && sum >= v[i + 1][0])
        {
            vec t = {sum + 1, -1};
            ll j = lower_bound(all(v), t, [&](auto &a, auto &b){
                return a[0] < b[0];
            }) - v.begin() - 1;
            sum += (prefix_sum[j] - prefix_sum[i]);
            ans[v[k][1]] += (j - i);
            i = j;
        }
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}