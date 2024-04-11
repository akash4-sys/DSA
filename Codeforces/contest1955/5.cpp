#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pl(x) cout << x << endl

int solve()
{
    int n = II;
    string s = SS;
    for (int k = n; k; k--)
    {
        string r = s;
        int cnt = 0;
        vector<int> op(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cnt -= op[i];
            r[i] ^= (cnt & 1);
            if (r[i] == '0')
            {
                if (i + k > n)
                    break;
                cnt++;
                op[i + k]++;
                r[i] = '1';
            }
        }

        if (r.find('0') == string::npos)
            return k;
    }
    return 1;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}