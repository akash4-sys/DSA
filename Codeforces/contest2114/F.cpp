#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

int solve(int x, int k)
{
    vector<int> v;
    for (int i = 1, sq = sqrt(x); i <= sq; i++)
        if (x % i == 0) {
            if (x / i != i)
                v.push_back(x / i);
            v.push_back(i);
        }
    sort(all(v));

    vector<int> dp(v.size(), 100);
    dp[0] = 0;
    for (int i = 1; i < v.size(); i++)
        for (int j = i - 1; j >= 0;  j--)
            if (v[i] % v[j] == 0 && v[i] / v[j] <= k)
                dp[i] = min(dp[i], dp[j] + 1);
    return dp.back() == 100 ? -1 : dp.back();
}

int solve()
{
    int x = II, y = II, k = II, ans = 0, g = __gcd(x, y);
    x /= g, y /= g;
    int a = solve(x, k), b = solve(y, k);
    return a == -1 || b == -1 ? -1 : a + b;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}