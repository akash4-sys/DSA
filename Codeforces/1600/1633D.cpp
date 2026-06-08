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

vec op;

int solve()
{
    int n = II, K = II, maxCost = 0;
    vec b(n), c(n);
    for (auto &x : b)
        x = op[II], maxCost += x;
    iv(c);

    if (maxCost <= K)
        return accumulate(all(c), 0);
    
    vector<int> dp(K + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int k = K; k >= 0; k--)
            if (k >= b[i])
                dp[k] = max(dp[k], dp[k - b[i]] + c[i]);
    }
    return dp[K];
}

int main()
{
    fast;
    op.resize(1001, 1000);
    op[1] = 0;
    for (int i = 1; i <= 1000; i++)
        for (int x = 1; x <= i; x++) {
            int j = i + (i / x);
            if (j < 1001)
                op[j] = min(op[j], op[i] + 1);
        }

    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}