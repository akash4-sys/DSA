#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })

int solve()
{
    int n = II;
    string s = SS;
    for (int k = n; k > 1; k--)
    {
        int x = 0, flag = 1;
        vector<int> v(n + 1, 0);
        for (int i = 0; i < n && flag; i++) {
            x ^= v[i];
            if ((s[i] - '0') ^ x == 0) {
                if (i + k <= n)
                    x ^= 1, v[i + k] ^= 1;
                else
                    flag = 0;
            }
        }
        if (flag)
            return k;
    }
    return 1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}