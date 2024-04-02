#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define iv(v) { for(auto &x : v) cin >> x; }

vec solve()
{
    int n = II, maxk = 0;
    vector<int> univ(n);
    iv(univ);
    
    vv univ_skill(n + 1);
    for (int i = 0; i < n; i++)
        univ_skill[univ[i]].push_back(II);
    
    vec ans(n, 0);
    for (auto &skill : univ_skill)
    {
        sort(all(skill), greater<ll>());
        int cnt = skill.size();
        for (int i = 1; i < cnt; i++)
            skill[i] += skill[i - 1];
        
        for (int k = 1; k <= cnt; k++)
            ans[k - 1] += skill[cnt - (cnt % k) - 1];
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