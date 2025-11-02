#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, x;
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> x;
        for (int d = 1, sq = sqrt(x); d <= sq; d++)
            if (x % d == 0)
                ans += (x / d != d) + 1;
        cout << ans << "\n";
    }
    return 0;
}