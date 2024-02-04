#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl
#define f first
#define s second

int solve()
{
    int n = II, ans = 0;
    vector<vector<pair<int, int>>> v;
    for (int k = 0; k < 3; k++)
    {
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++)
            a.push_back({II, i});
        sort(all(a));
        v.push_back({a.back(), a[n - 2], a[n - 3]});
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
            {
                int x = v[0][i].s, y = v[1][j].s, z = v[2][k].s;
                if (x != y && y != z && z != x)
                    ans = max(ans, v[0][i].f + v[1][j].f + v[2][k].f);
            }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}