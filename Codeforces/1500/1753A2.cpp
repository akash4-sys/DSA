#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

void solve()
{
    int n = II, neg = 0, cnt = 0;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        a[i] = II, neg += (a[i] < 0), cnt += (a[i] != 0);
    
    if (cnt % 2) {
        cout << -1 << "\n";
        return;
    }

    int i = 0;
    vector<vector<int>> ans;
    for (; i < n - 1; i++)
    {
        if (neg < cnt / 2 && a[i + 1] == 1)
            ans.push_back({i + 1, i + 2}), a[++i] *= -1, neg++;
        else if (neg > cnt / 2 && a[i + 1] == -1)
            ans.push_back({i + 1, i + 2}), a[++i] *= -1, neg--;
        else
            ans.push_back({i + 1, i + 1});
    }

    if (i < n)
        ans.push_back({i + 1, i + 1});

    cout << ans.size() << "\n";
    for (auto &v : ans)
        cout << v[0] << " " << v[1] << "\n";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}