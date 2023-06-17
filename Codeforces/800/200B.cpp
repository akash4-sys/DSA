#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

int main()
{
    double n, sum = 0.0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double a;
        cin >> a;
        sum += a;
    }

    double ans = sum / (n * 1.0);
    cout << ans << endl;
    return 0;
}