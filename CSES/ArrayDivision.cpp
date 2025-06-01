#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    long long l = 0, r = 3e14;
    vector<int> v(n);
    for (int &a : v)
        cin >> a, l = max(l, (long long)a);
    
    while (l <= r)
    {
        long long x = l + ((r - l) / 2), cuts = 0, sum = 0;
        for (int &a : v) {
            if (sum + a > x)
                cuts++, sum = 0;
            sum += a;
        }
        if (cuts < k)
            r = x - 1;
        else
            l = x + 1;
    }
    cout << r + 1;
    return 0;
}