#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define br cout << endl

void solve()
{
    int n = II;
    vector bitsPf(n, vector<int>(32, 0));
    for (int i = 0; i < n; i++)
    {
        int a = II;
        for (int j = 0; j < 32; j++)
            bitsPf[i][j] += (i ? bitsPf[i - 1][j] : 0) + (!!(a & (1 << j)));
    }

    for (int q = II; q; q--)
    {
        int left = II - 1, k = II, l = left, r = n - 1, ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2, num = 0;
            for (int i = 0; i < 32; i++)
                if (bitsPf[mid][i] - (left ? bitsPf[left - 1][i] : 0) == mid - left + 1)
                    num |= (1 << i);
            
            if (num >= k)
                l = mid + 1, ans = mid + 1;
            else
                r = mid - 1;
        }
        pf(ans);
    }
    br;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}