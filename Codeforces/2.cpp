#ifdef __INTELLISENSE__
#include "../headers.h"
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

int solve()
{
    int n = II, on = 0;
    unordered_map<int, priority_queue<int>> mp;
    for (int i = 0; i < n; i++) {
        int a = II, b = II;
        mp[a].push(b);
    }

    int ans = 0;
    vec v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!mp.count(i))
            continue;
        
        auto pq = mp[i];
        while (pq.size())
        {
            ans += pq.top();
            pq.pop();
            on++;
            v[i]++;
            int x = on;
            on -= v[on];
            v[on] = 0;
            if (x == i) {
                break;
            }
        }
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        pl(solve());
    return 0;
}