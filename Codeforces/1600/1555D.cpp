#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pv(v) {{ for(auto &x : v) cout << x << " "; } cout << endl;}

int main()
{
    fast;
    int n = II, m = II;
    string s = SS;

    vector<string> v = {"ab", "ac", "ba", "bc", "ca", "cb"};
    vector<vector<int>> dp(6, vector<int>(n + 1, 0));
    for (int i = 0; i < 6; i++)
    {
        string r = v[i];
        dp[i][0] = s[0] != r[0];
        dp[i][1] += dp[i][0] + (s[1] != r[1]);
        for (int j = 2; j < n; j++)
            for (char c = 'a'; c <= 'c'; c++)
                if (c != r[0] && c != r[1])
                {
                    dp[i][j] += dp[i][j - 1] + (c != s[j]);
                    r[0] = r[1];
                    r[1] = c;
                    break;
                }
    }

    while (m--)
    {
        int l = II - 1, r = II - 1, ans = n;
        for (int i = 0; i < 6; i++)
            ans = min(ans, dp[i][r] - (l > 0 ? dp[i][l - 1] : 0));
        cout << ans << "\n";
    }
    return 0;
}