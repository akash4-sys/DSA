#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define iv(v) { for(auto &x : v) cin >> x; }

void gen(int n, vec &a, vec &p)
{
    vec v(n + 1, 0);
    vv left;
    for (int i = 0; i < n; i++)
        if (!v[a[i]])
            p[i] = a[i], v[a[i]] = 1;
        else
            left.push_back({a[i], i});
    
    sort(all(left));
    for (int i = 1, j = 0; i <= n; i++)
        if (!v[i])
            p[left[j][1]] = i, j++;
}

void solve()
{
    int n = II;
    vec p(n), q(n), a(n);
    iv(a);
    
    gen(n, a, p);
    reverse(all(a));
    gen(n, a, q);
    reverse(all(q));

    for (int i = 0; i < n; i++)
        if (max(p[i], q[i]) != a[n - i - 1]) {
            pl("NO");
            return;
        }

    pl("YES");
    pv(p);
    pv(q);
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        solve();
    return 0;
}