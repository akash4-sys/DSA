#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve()
{
    int n, k, m, mask = 0, cnt = 0;
    string s, ans = "";
    cin >> n >> k >> m >> s;

    for (int i = 0; i < m && ans.size() != n; i++)
    {
        cnt += !(mask & (1 << (s[i] - 'a')));
        mask |= (1 << (s[i] - 'a'));
        if (cnt == k)
            ans += s[i], cnt = 0, mask = 0;
    }

    if (ans.size() == n)
        cout << "YES\n";
    else
    {
        for (int i = 0; i < k; i++)
            while (!(mask & (1 << i)) && ans.size() != n)
                ans += char(i + 'a');
        cout << "NO\n" << ans << endl;
    }
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