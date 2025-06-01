#include <bits/stdc++.h>
using namespace std;

long long count(string &s)
{
    long long dp[20][10][2][2];
    memset(dp, 0, sizeof(dp));
    for (int p = 0; p < 10; p++)
        for (int zero = 0; zero < 2; zero++)
            for (int bound = 0; bound < 2; bound++)
                dp[s.size()][p][zero][bound] = 1;

    for (int i = s.size() - 1; i >= 0; i--)
        for (int p = 0; p < 10; p++)
            for (int zero = 0; zero < 2; zero++)
                for (int bound = 0; bound < 2; bound++)
                {
                    int limit = bound ? s[i] - '0' : 9;
                    for (int d = 0; d <= (bound ? s[i] - '0' : 9); d++)
                        if (d != p || (zero && !d))
                            dp[i][p][zero][bound] += dp[i + 1][d][zero && !d][bound && (d == limit)];
                }
    return dp[0][0][1][1];
}

int main()
{
    long long a, b;
    cin >> a >> b;
    string s = to_string(a - 1), r = to_string(b);
    cout << count(r) - count(s);
    return 0;
}