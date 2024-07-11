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
        int n = II, sum = 0, ans = n * n + 1;
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0, k = (n - i) % n; j < n; j++)
            {
                cnt[k] += (s[j] == '1');
                sum += (s[j] == '1');
                k = (k + 1) % n;
            }
        }

        for (int &c : cnt)
            ans = min(ans, sum + n - c * 2);
        cout << ans << "\n";
    }
    return 0;
}