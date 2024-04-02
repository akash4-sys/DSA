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
    ll n = LL, pos = -1;
    string s;
    cin >> s;

    ll cnt = count(s.begin(), s.end(), '*'), m = cnt / 2;
    for (int i = 0, j = 0; j <= m && i < n; i++)
        if (s[i] == '*')
            pos = i, j++;
    
    ll ans = 0, curr = pos - m;
    for (int i = 0; i < n; i++)
        if (s[i] == '*')
            ans += abs(curr - i), curr++;
    return ans;
}

int main()
{
    fast;
    int tc = LL;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}