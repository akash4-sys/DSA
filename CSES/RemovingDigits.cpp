#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    while (n > 0) {
        int d = 0;
        for (int x = n; x; x /= 10)
            d = max(d, x % 10);
        n -= d;
        ans++;
    }
    cout << ans;
    return 0;
}