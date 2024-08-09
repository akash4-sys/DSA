#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

ll solve()
{
    ll n = LL, m = LL;
    vector<vector<ll>> v(n, vector<ll>(2));
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < n; i++)
            v[i][j] = LL;
    sort(v.begin(), v.end());
    
    ll ans = min(m / v[0][0], v[0][1]) * v[0][0];
    for (int i = 1; i < n; i++)
        if (v[i][0] - v[i - 1][0] == 1)
        {
            ll a = min(m / v[i - 1][0], v[i - 1][1]), coins = m - (a * v[i - 1][0]);
            ll b = min(coins / v[i][0], v[i][1]);
            coins -= (b * v[i][0]);
            ll k = min({a, v[i][1] - b, coins});
            ans = max(ans, ((a - k) * v[i - 1][0]) + ((b + k) * v[i][0]));
        }
        else
            ans = max(ans, min(m / v[i][0], v[i][1]) * v[i][0]);
    return ans;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        cout << solve() << endl;
    return 0;
}