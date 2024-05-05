#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int query(int l, int r)
{
    if (l >= r)
        return -1;

    cout << "? " << l + 1 << " " << r + 1 << endl;
    cout.flush();
    int i;
    cin >> i;
    return i - 1;
}

int main()
{
    fast;
    int n;
    cin >> n;
    int l = 0, r = n;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        int i = query(l, r - 1);
        if (i < mid) {
            if (query(l, mid - 1) == i)
                r = mid;
            else
                l = mid;
        }
        else {
            if (query(mid, r - 1) == i)
                l = mid;
            else
                r = mid;
        }
    }
    cout << "! " << r << endl;
    return 0;
}