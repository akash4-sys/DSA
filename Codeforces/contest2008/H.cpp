#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

void solve()
{
    int n = II, q = II;
    vector<int> cnt(n + 1, 0), ans(n + 1, 0);
    for (int i = 0; i < n; i++)
        cnt[II]++;
    for (int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
    
    for (int x = 1; x <= n; x++)
    {
        int l = 0, r = x;
        while (l < r)
        {
            int m = (l + r) / 2, count = cnt[m];
            for (int k = 1; k * x <= n; k++)
                count += cnt[min(k * x + m, n)] - cnt[k * x - 1];
            if (count - 1 >= n / 2)
                r = m;
            else
                l = m + 1;
        }
        ans[x] = l;
    }

    while (q--)
        cout << ans[II] << " ";
    cout << "\n";
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}