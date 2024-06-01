#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

// @ Came up with dp solution beforet this one myself
// @ try to understand the editorial its very hard

bool solve()
{
    int n = II, cnt[2] = {0}, m = (n + 1) / 2;
    for (int i = 0; i < n; i++)
        cnt[((II % 2) + 2) % 2]++;
    for (int o = 0; o <= min(m, cnt[1]); o += 2)
        if (m - o <= cnt[0] && o <= ((cnt[1] + 1) / 2) && m - o <= ((cnt[0] + 1) / 2))
            return 1;
    return 0;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << (solve() ? "Alice" : "Bob") << endl;
    return 0;
}