#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

bool solve()
{
    int n = II, mx = -1, mn = n, cnt = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            cnt++, mx = max(mx, i), mn = min(mn, i);
    return !(cnt % 2 == 1 || (cnt == 2 && mx - mn == 1));
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}