#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    int n;
    cin >> n;
    int k = n / 2;
    int ans = n % 2 ? (k + 1) * (k + 2) * 2 : (k + 1) * (k + 1);
    cout << ans;
    return 0;
}