#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int solve()
{
    int n = II;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[II]++;

    vector<int> cnt;
    for (auto &it : mp)
        cnt.push_back(it.second);
    
    vector<vector<int>> dp(cnt.size(), vector<int>(cnt.size(), -1));
    function<int(int, int)> rec = [&](int i, int moves) -> int {
        if (i == cnt.size())
            return 0;
        if (dp[i][moves] != -1)
            return dp[i][moves];
        
        int res = rec(i + 1, moves + 1);
        if (cnt[i] <= moves)
            res = max(res, rec(i + 1, moves - cnt[i]) + 1);
        return dp[i][moves] = res;
    };
    return cnt.size() - rec(0, 0);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}