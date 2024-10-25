#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }
#define iv(v) { for(auto &x : v) cin >> x; }

void solve()
{
    int n = II, k = II, q = II;
    vec v(n), lis(n);
    for (int i = 0; i < n; i++)
        v[i] = II - i - 1;

    map<int, int> mp, fq;
    auto update = [&](int i, int inc) {
        if (mp.count(fq[v[i]]))
            mp[fq[v[i]]]--;
        if (mp[fq[v[i]]] <= 0)
            mp.erase(fq[v[i]]);
        if (inc)
            mp[++fq[v[i]]]++;
    };

    for (int i = 0; i < k; i++)
        update(i, 1);

    lis[0] = mp.rbegin()->first;
    for (int i = 1; i < n - k + 1; i++) {
        update(i - 1, 0);
        mp[--fq[v[i - 1]]]++;
        update(i + k - 1, 1);
        lis[i] = mp.rbegin()->first;
    }
    
    while (q--) {
        int l = II - 1, r = II - 1;
        cout << k - lis[l] << "\n";
    }
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}