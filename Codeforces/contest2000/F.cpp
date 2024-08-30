#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

vector<int> a, b;
int dp[1001][201], n, inf = 1e5;

int rec(int i, int k)
{
    if (!k)
        return 0;
    if (i == n)
        return inf;
    if (dp[i][k] != -1)
        return dp[i][k];
    
    int res = inf, cost = 0, x = a[i], y = b[i], points = x + y;
    for (int j = 0; j <= min(points, k); j++)
    {
        res = min(res, rec(i + 1, k - j) + cost);
        if (x >= y)
            x--, cost += y;
        else
            y--, cost += x;
    }
    return dp[i][k] = res;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
    {
        n = II;
        int k = II;
        a.resize(n, 0);
        b.resize(n, 0);
        for (int i = 0; i < n; i++)
            a[i] = II, b[i] = II;
        
        memset(dp, -1, sizeof(dp));
        int ans = rec(0, k);
        cout << (ans == inf ? -1 : ans) << "\n";
    }
    return 0;
}