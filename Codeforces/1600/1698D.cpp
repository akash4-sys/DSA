#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    assert(n != -1);

    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) / 2, cnt = 0, a;
        cout << "? " << l << " " << mid << endl;
        for (int i = 0; i < mid - l + 1; i++) {
            cin >> a;
            assert(a != -1);
            cnt += l <= a && a <= mid;
        }

        if (cnt % 2 == 0)
            l = mid + 1;
        else
            r = mid;
    }
    cout << "! " << l << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}