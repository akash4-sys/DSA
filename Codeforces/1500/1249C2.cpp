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
    ll n = LL, ans = 0, p = 1;
    string s = "";
    for (ll N = n; N; N /= 3)
        s += to_string(N % 3);
    reverse(s.begin(), s.end());

    int i = s.find('2');
    if (i == string::npos)
        return n;

    for (; i >= 0 && s[i] != '0'; i--);
    for (int j = s.size() - 1; j > i; j--)
        p *= 3LL;
    if (i == -1)
        return p;

    s[i] = '1';
    for (int j = i; j >= 0; j--, p *= 3LL)
        ans += (1LL * (s[j] - '0') * p);
    return ans;
}

int main()
{
    fast;
    for (int t = LL; t--;)
        cout << solve() << "\n";
    return 0;
}