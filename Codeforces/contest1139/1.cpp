#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    int n;
    string s;
    cin >> n >> s;

    long long ans = 0;
    for (int i = 0; i < n; i++)
        if ((s[i] - '0') % 2 == 0)
            ans += (i + 1);
    cout << ans;
    return 0;
}