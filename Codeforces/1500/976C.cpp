#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a ; a; })

int main()
{
    fast;
    int n = II;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
        v[i] = {II, II, i + 1};
    
    sort(v.begin(), v.end(), [&](auto &a, auto &b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });

    map<int, int> mp;
    int i = n - 1, j = -1;
    for (; i >= 0; i--)
    {
        auto it = mp.upper_bound(v[i][1]);
        if (mp.size() && it != mp.begin()) {
            j = v[i][2], i = prev(it)->second;
            break;
        }
        mp[v[i][1]] = v[i][2];
    }
    cout << i << " " << j;
    return 0;
}