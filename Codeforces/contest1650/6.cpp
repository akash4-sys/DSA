#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

vector<int> ans;

bool calc(vector<vector<int>> &v, ll deadline, ll &globalTime)
{
    sort(v.begin(), v.end());
    ll x = -1, y = -1, ctime = 0, time = LLONG_MAX, percent = 0;
    for (int i = 0, j = 0; i < v.size(); i++)
    {
        ctime += v[i][0];
        percent += v[i][1];
        while (j < i && percent - v[j][1] >= 100)
            ctime -= v[j][0], percent -= v[j][1], j++;
        if (percent >= 100 && ctime + globalTime <= deadline && ctime < time)
            x = j, y = i, time = ctime;
    }

    if (x == -1) {
        ans.clear();
        return 0;
    }

    globalTime += time;
    for (int i = x; i <= y; i++)
        ans.push_back(v[i][2] + 1);
    return 1;
}

void solve()
{
    ans.clear();
    int n = II, m = II;
    vector<vector<vector<int>>> v(n);
    vector<ll> a(n);
    for (ll &x : a)
        x = II;
    for (int i = 0; i < m; i++)
        v[II - 1].push_back({II, II, i});
    
    if (m < n)
        return;
    
    ll time = 0;
    for (int i = 0; i < n; i++)
        if (!calc(v[i], a[i], time))
            return;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
    {
        solve();
        if (ans.empty()) {
            cout << "-1\n";
            continue;
        }

        cout << ans.size() << "\n";
        for (int &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}