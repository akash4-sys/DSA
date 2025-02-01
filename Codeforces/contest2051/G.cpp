#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> id(q), ch(q), len(n, 0);
    for (int i = 0; i < q; i++) {
        char c;
        cin >> id[i] >> c;
        id[i]--;
        ch[i] = c == '+' ? 1 : -1;
        len[id[i]] += ch[i] > 0;
    }

    vector<vector<int>> minDist(n, vector<int>(n, INT_MAX)), dp(1 << n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int sum = 0, x = 0;
            for (int k = 0; k < q; k++) {
                if (id[k] == i)
                    sum -= ch[k] > 0;
                if (id[k] == j)
                    sum += ch[k] < 0;
                x = min(x, sum);
            }
            minDist[i][j] = -x + 1;
        }
    
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = 1;
    
    for (int mask = 1; mask < (1 << n); mask++)
        for (int i = 0; i < n; i++)
            if (dp[mask][i] != INT_MAX)
                for (int j = 0; j < n; j++)
                {
                    if (mask & (1 << j))
                        continue;
                    int next_mask = mask | (1 << j);
                    dp[next_mask][j] = min(dp[next_mask][j], dp[mask][i] + minDist[i][j]);
                }
    
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[(1 << n) - 1][i] + len[i]);
    cout << ans;
    return 0;
}