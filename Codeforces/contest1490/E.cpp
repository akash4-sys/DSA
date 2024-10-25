#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}

vec solve()
{
    int n = LL;
    vv v(n);
    for (int i = 0; i < n; i++)
        v[i] = {LL, i + 1};

    vec sum, ans, dp(n, 0);
    sort(all(v));
    for (auto &a : v)
        sum.push_back(sum.size() ? sum.back() + a[0] : a[0]);
    
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        vec t = {sum[i], INT_MAX};
        int j = upper_bound(all(v), t) - v.begin() - 1;
        dp[i] = dp[j];
    }

    for (int i = 0; i < n; i++)
        if (dp[i])
            ans.push_back(v[i][1]);
    pl(ans.size());
    sort(all(ans));
    return ans;
}

int main()
{
    fast;
    for (int tc = LL; tc; tc--)
        pv(solve());
    return 0;
}