#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, r;
    cin >> s >> r;
    int m = s.size(), n = r.size();
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
        dp[i] = i;
    
    for (int i = 1; i <= m; i++)
    {
        int prev = i - 1;
        dp[0] = i;
        for (int j = 1; j <= n; j++)
        {
            int curr = dp[j];
            if (s[i - 1] == r[j - 1])
                dp[j] = prev;
            else
                dp[j] = min({dp[j], dp[j - 1], prev}) + 1;
            prev = curr;
        }
    }
    cout << dp[n];
    return 0;
}