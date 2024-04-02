#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pl(x) cout << x << endl

int dp[65537][16], poss[16][16], n;

int rec(int mask, int i)
{
    if (dp[mask][i] != -1)
        return dp[mask][i];

    int res = 0;
    for (int j = 0; j < n; j++)
        if (!(mask & (1 << j)) && poss[i][j])
            res = max(res, rec(mask | (1 << j), j) + 1);
    return dp[mask][i] = res;
}

int solve()
{
    memset(dp, -1, sizeof(dp));
    memset(poss, 0, sizeof(poss));

    n = II;
    vector<vector<string>> song;
    for (int i = 0; i < n; i++)
        song.push_back({SS, SS});
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && (song[i][0] == song[j][0] || song[i][1] == song[j][1]))
                poss[j][i] = poss[i][j] = 1;
    
    int m = 0;
    for (int i = 0; i < n; i++)
        m = max(m, rec(1 << i, i) + 1);
    return n - m;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}