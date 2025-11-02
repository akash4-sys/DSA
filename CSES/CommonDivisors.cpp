#include <bits/stdc++.h>
using namespace std;

#define II ({ int a; cin >> a ; a; })

int main()
{
    int n = II, x = 1e6;
    vector<int> mp(x + 1, 0);
    for (int i = 0; i < n; i++) {
        int a = II, sq = sqrt(a);
        for (int d = 1; d <= sq; d++)
            if (a % d == 0) {
                if (a / d != d) mp[a / d]++;
                mp[d]++;
            }
    }

    while (x >= 1 && mp[x] < 2) x--;
    cout << x;
    return 0;
}