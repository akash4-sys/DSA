#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

ll solve()
{
    ll n = LL, k = LL;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        a[i] = LL;
    
    sort(a.begin(), a.end());
    a.push_back(0);
    ll sum = a[1], i = 1;
    while (i <= n && a[i] * i - sum <= k)
        sum += a[++i];

    i--;
    k -= ((a[i] * i) - (sum - a[i + 1]));
    a[i] += (k / i);
    return n * (a[i] - 1) + (k % i) + n - i + 1;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}