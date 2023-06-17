#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    int k, l, m, n, d, cnt = 0;
    cin >> k >> l >> m >> n >> d;
    for (int i = 1; i <= d; i++)
        cnt += (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0);
    cout << cnt << endl;
    return 0;
}