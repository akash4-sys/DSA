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
    int tc = II;
    while (tc--)
    {
        int n = II, x = 0, cnt = 0, cx = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = II, x ^= v[i];
        
        if (!x) {
            cout << "YES\n";
            continue;
        }

        for (int &a : v) {
            cx ^= a;
            if (x == cx)
                cnt++, cx = 0;
        }
        cout << (cnt >= 3 ? "YES" : "NO") << "\n";
    }
    return 0;
}