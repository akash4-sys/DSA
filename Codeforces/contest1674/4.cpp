#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vec vector<int>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl
#define iv(v) { for(auto &x : v) cin >> x; }

bool solve()
{
    int n = II;
    vec a(n);
    iv(a);
    int m = *min_element(a.begin(), a.end());
    if (n % 2 && a[0] != m)
        return 0;
    
    for (int i = n % 2; i < n; i += 2)
        if (a[i] > a[i + 1])
            swap(a[i], a[i + 1]);
    return is_sorted(a.begin(), a.end());
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl((solve() ? "yes" : "no"));
    return 0;
}