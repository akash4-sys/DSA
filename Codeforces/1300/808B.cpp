#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define ld long double

int main()
{
    cout.precision(10);
    cout.setf(ios::fixed);

    int n, k;
    cin >> n >> k;
    vector<ld> v(n);
    for (ld &a : v)
        cin >> a;
    
    ld sum = accumulate(v.begin(), v.begin() + k, 0.0), weeks = n - k + 1, total = sum;
    for (int i = 1; i < weeks; i++) {
        sum -= v[i - 1];
        sum += v[i + k - 1];
        total += sum;
    }

    ld ans = total / weeks;
    cout << ans;
    return 0;
}