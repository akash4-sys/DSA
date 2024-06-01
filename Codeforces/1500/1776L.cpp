#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

int main()
{
    fast;
    int n = II;
    string s;
    cin >> s;

    int p = count(s.begin(), s.end(), '+'), m = n - p;
    for (int q = II; q; q--)
    {
        ll a = II, b = II, ans = 0, num = (p - m) * b, d = b - a;
        ans = (p == m || (a != b && num % d == 0 && num / d >= -m && num / d <= p));
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}