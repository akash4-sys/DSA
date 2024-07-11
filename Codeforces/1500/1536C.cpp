#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string c; cin >> c; c; })

void solve()
{
    int n = II, d = 0, k = 0;
    string s = SS;
    map<pair<int, int>, int> ratio;
    for (char &c : s) {
        c == 'D' ? d++ : k++;
        int g = __gcd(d, k), a = d / g, b = k / g;
        cout << ++ratio[{a, b}] << " ";
    }
    cout << "\n";
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}