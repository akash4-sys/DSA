#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define vvv vector<vv>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define iv(v) { for(auto &x : v) cin >> x; }

vector<int> solve()
{
    int n = II;
    vector<int> a(n), ans(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
        a[i] = II, mp[a[i] - (a[i] % 4)].push_back(i);
    
    for (auto &[m, v] : mp)
        sort(v.begin(), v.end(), [&](int &i, int &j){
            return a[i] < a[j];
        });
    
    for (int i = n - 1; i >= 0; i--) {
        int m = a[i] - (a[i] % 4);
        ans[i] = a[mp[m].back()];
        mp[m].pop_back();
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pv(solve());
    return 0;
}