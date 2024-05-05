#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    int n = II, mex = 0;
    vector<vector<int>> idx(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u = II, v = II;
        idx[u].push_back(i);
        idx[v].push_back(i);
    }

    vector<int> ans(n, -1);
    for (int i = 1; i <= n; i++)
        if (idx[i].size() >= 3) {
            for (int j : idx[i])
                ans[j] = mex++;
            break;
        }
    
    for (int i = 0; i < n - 1; i++)
        cout << (ans[i] == -1 ? mex++ : ans[i]) << "\n";
    return 0;
}