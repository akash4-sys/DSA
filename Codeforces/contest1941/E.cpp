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

ll solve()
{
    ll n = LL, m = LL, k = LL, d = LL;
    vv v(n, vec(m));
    for (auto &r : v)
        iv(r);
    
    vec cost;
    for (auto &r : v)
    {
        vec dp(m, 1e9);
        multiset<ll> st = {1};
        dp[0] = 1;
        for (int j = 1; j < m - 1; j++)
        {
            dp[j] = *st.begin() + r[j] + 1;
            if (j - d - 1 >= 0)
                st.erase(st.find(dp[j - d - 1]));
            st.insert(dp[j]);
        }
        cost.push_back(*st.begin() + 1);
    }

    ll sum = 0;
    for (int i = 0; i < k; i++)
        sum += cost[i];
    
    ll ans = sum;
    for (int i = 1; i < n - k + 1; i++) {
        sum += cost[i + k - 1] - cost[i - 1];
        ans = min(ans, sum);
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