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
    ll n = LL, ans = 0;
    for (int i = 0; i < 60; i++)
        if (n & (1LL << i))
            ans += (1LL << (i + 1)) - 1;
    return ans;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        cout << solve() << endl;
    return 0;
}