#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fast;
    int n, m, colors = 1e5 + 1, col;
    cin >> n >> m;
    vector<vector<vector<int>>> coords(colors, vector<vector<int>>(2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> col;
            coords[col][0].push_back(i);
            coords[col][1].push_back(j);
        }
    
    long long ans = 0;
    for (auto &cod : coords)
        if (cod[0].size())
        {
            sort(cod[0].begin(), cod[0].end());
            sort(cod[1].begin(), cod[1].end());

            long long sumx = cod[0][0], sumy = cod[1][0];
            for (int i = 1; i < cod[0].size(); i++)
            {
                ans += (1LL * cod[0][i] * i - sumx);
                ans += (1LL * cod[1][i] * i - sumy);
                sumx += cod[0][i];
                sumy += cod[1][i];
            }
        }
    
    cout << ans;
    return 0;
}