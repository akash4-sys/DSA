#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ ll a; cin>>a; a; })
#define pl(x) cout << x << endl

bool solve()
{
    int n = LL, c = LL, d = LL;
    vector<ll> a(n * n), b;
    for (auto &x : a)
        x = LL;
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b.push_back(a[0] + (c * i) + (d * j));
    sort(b.begin(), b.end());
    return a == b;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        pl((solve() ? "yes" : "no"));
    return 0;
}