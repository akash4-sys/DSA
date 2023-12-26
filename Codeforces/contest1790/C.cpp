#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
        {
            int x;
            cin >> x;
            mp[x] += j;
        }

    map<int, int> res;
    for (auto [x, c] : mp)
        res[c] = x;

    for (auto &i : res)
        cout << i.second << " ";
    cout << endl;
}

int main()
{
    fast;
    int tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}