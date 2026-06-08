#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

bool ishere(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    int n = r - l + 1, cnt = 0;
    for (int i = l; i <= r; i++) {
        int a = II;
        cnt += (a < l || a > r);
    }
    return (n % 2 && cnt % 2 == 0) || (n % 2 == 0 && cnt % 2);
}

void solve()
{
    int n = II;
    assert(n != -1);
    
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (ishere(l, mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << "! " << r << endl;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}