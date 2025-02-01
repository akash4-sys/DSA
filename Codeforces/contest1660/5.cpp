#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    int tc = II;
    while (tc--)
    {
        int n = II, cnt = 0, d = 0;
        vector<string> v(n);
        for (auto &s : v) {
            cin >> s;
            cnt += count(s.begin(), s.end(), '1');
        }
        for (int k = 0; k < n; k++) {
            int c = 0;
            for (int i = 0, j = k, m = n; m; m--)
                c += v[i][j] == '1', i = (i + 1) % n, j = (j + 1) % n;
            d = max(d, c);
        }
        cout << cnt + n - (d * 2) << "\n";
    }
    return 0;
}