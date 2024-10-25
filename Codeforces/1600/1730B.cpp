#include <bits/stdc++.h>
using namespace std;

#define d double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LL ({ d a; cin>>a ; a; })
#define iv(v) { for(auto &x : v) cin >> x; }

d solve()
{
    d n = LL, x = 0, y = DBL_MAX;
    vector<d> v(n), t(n);
    iv(v); iv(t);
    for (int i = 0; i < n; i++)
        x = max(x, v[i] + t[i]), y = min(y, v[i] - t[i]);
    return (x + y) / 2.0;
}

int main()
{
    fast;
    cout.precision(10);
    cout.setf(ios::fixed);
    for (int tc = LL; tc; tc--)
        cout << solve() << "\n";
    return 0;
}