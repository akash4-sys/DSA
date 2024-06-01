#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pv(v) {{ for(auto &x : v) cout << x << " "; } cout << "\n";}

vector<int> solve()
{
    int n = II;
    vector<int> q(n), pos(n + 1);
    for (int i = 0; i < n; i++) {
        int a = II;
        q[i] = n + 1 - a;
        pos[a] = i;
    }

    for (int i = 1; i <= n; i++)
        if (pos[i] % 2 != pos[1] % 2)
            swap(q[pos[i]], q[pos[1]]);
    return q;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}