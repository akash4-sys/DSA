#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<int>
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
#define pv(v) { for(auto &x : v) pf(x)<<" "; }
#define pvv(mat) { for(auto &r : mat) {pv(r); br;} }
#define iv(v) { for(auto &x : v) cin >> x; }

string solve()
{
    string s = SS, ans = "";
    int cnt[4] = {0};
    for (char c : s)
        if (isdigit(c))
            cnt[c - '0']++;
    
    for (int i = 1; i < 4; i++)
        while (cnt[i]--)
            ans += to_string(i) + "+";
    ans.pop_back();
    return ans;
}

int main()
{
    fast;
    pl(solve());
    return 0;
}