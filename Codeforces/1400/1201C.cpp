#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a ; a; })

int main()
{
    fast;
    ll n = LL, k = LL, m = n / 2;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        a[i] = LL;
    
    sort(a.begin(), a.end());
    a.push_back(INT_MAX);
    for (int i = m; i < n; i++)
    {
        ll d = a[i + 1] - a[i], fq = i - m + 1;
        if (d * fq > k) {
            cout << a[i] + (k / fq);
            return 0;
        }
        k -= (d * fq);
        a[i] = a[i + 1];
    }
    return 0;
}