#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << "\n"
#define pv(v) {{ for(auto &x : v) cout << x << " "; } cout << "\n";}
#define iv(v) { for(auto &x : v) cin >> x; }

vector<int> minOp;
int solve()
{
    int n = II, k = II, sum = 0;
    vector<int> op(n), c(n);
    for (int &b : op)
        b = minOp[II], sum += b;
    iv(c);

    k = min(sum, k);
    vector<int> dp(sum + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> dp2(sum + 1, 0);
        for (int j = 0; j <= sum; j++) {
            dp2[j] = dp[j];
            if (j >= op[i])
                dp2[j] = max(dp2[j], dp[j - op[i]] + c[i]);
        }
        swap(dp2, dp);
    }
    return *max_element(all(dp));
}

int main()
{
    fast;
    minOp = vector<int>(1001, 1001);
    minOp[1] = 0;
    for (int i = 1; i < 1001; i++)
        for (int x = 1; x <= i; x++) {
            int j = i + (i / x);
            if (j < 1001)
                minOp[j] = min(minOp[j], minOp[i] + 1);
        }

    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}