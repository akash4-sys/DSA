#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
const int N = 2e5 + 1;

class Solution
{
    int dp[N][100], mp[N];
    int rec(int u, int cnt)
    {
        cnt += mp[u];
        int res = cnt;
        if (dp[u][cnt] >= res)
            return dp[u][cnt];

        for (int i = 2, sq = sqrt(u); i <= sq; i++)
            if (u % i == 0)
            {
                if (u / i != i && mp[u / i])
                    res = max(res, rec(u / i, cnt));
                if (mp[i])
                    res = max(res, rec(i, cnt));
            }
        return dp[u][cnt] = max(dp[u][cnt], res);
    }

public:
    int solve()
    {
        int n = II, ans = 0;
        vector<int> v(n);
        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < n; i++)
            v[i] = II, mp[v[i]]++;

        sort(all(v), greater<int>());
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            if (v[i] != 1)
                ans = max(ans, rec(v[i], 0));
        return n - ans - mp[1];
    }
};

int main()
{
    fast;
    for (int tc = II; tc; tc--) {
        Solution sol;
        cout << sol.solve() << "\n";
    }
    return 0;
}