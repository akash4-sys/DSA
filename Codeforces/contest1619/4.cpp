#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl

bool check(vector<vector<int>> &v, int x)
{
    vector<bool> found(v[0].size(), 0);
    int avail = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < v[0].size(); j++)
            if (v[i][j] >= x)
                found[j] = 1, cnt++;
        avail += (cnt > 1);
    }

    if (!avail && v[0].size() > 1)
        return 0;
    return count(found.begin(), found.end(), 0) == 0;
}

int solve()
{
    int m = II, n = II, l = 1, r = 1e9;
    vector<vector<int>> v(m, vector<int>(n));
    for (auto &r : v)
        for (int &x : r)
            x = II;
    
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(v, mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l - 1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}