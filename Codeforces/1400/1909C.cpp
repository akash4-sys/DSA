#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pl(x) cout << x << "\n"
#define iv(v) { for(auto &x : v) cin >> x; }

ll solve()
{
    int n = II;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({II, 0});
    for (int i = 0; i < n; i++)
        v.push_back({II, 1});
    
    vector<int> c(n), l, wt;
    iv(c);
    sort(all(c), greater<int>());

    sort(all(v));
    for (int i = 0; i < n * 2; i++)
        if (!v[i][1])
            l.push_back(v[i][0]);
        else
            wt.push_back(v[i][0] - l.back()), l.pop_back();
    
    ll ans = 0;
    sort(all(wt));
    for (int i = 0; i < n; i++)
        ans += 1LL * c[i] * wt[i];
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}