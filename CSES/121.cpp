#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    int n, m, x;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    while (m--)
    {
        cin >> x;
        int i = lower_bound(v.begin(), v.end(), x) - v.begin();
        if (i == v.size())
        {
            cout << 0 << " ";
            continue;
        }
        v[i] -= x;
        cout << i + 1 << " ";
    }
    return 0;
}