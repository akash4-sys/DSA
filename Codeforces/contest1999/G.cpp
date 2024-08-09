#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void solve()
{
    int l = 2, r = 999, ans = 999;
    while (l <= r)
    {
        int a = l + ((r - l) / 3), b = r - ((r - l) / 3), area;
        cout << "? " << a << " " << b << endl;
        cin >> area;

        if (area == -1)
            return;
        
        if (area == (a + 1) * b || area == (a + 1) * (b + 1))
            r = a - 1, ans = min(ans, a);
        else if (area == a * (b + 1))
            l = a + 1, r = b - 1, ans = min(ans, b);
        else if (area == a * b)
            l = b + 1;
    }
    cout << "! " << ans << endl;
}

int main()
{
    fast;
    int tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}