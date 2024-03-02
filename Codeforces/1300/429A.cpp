#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vec vector<int>
#define vv vector<vec>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pl(x) cout << x << endl
#define pv(v) { for(auto &x : v) pl(x); }
#define iv(v) { for(auto &x : v) cin >> x; }

int main()
{
    fast;
    int n = II, odd_xor = 0, even_xor = 0;
    vv g(n);
    for (int i = 1; i < n; i++)
    {
        int u = II - 1, v = II - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vec val(n), goal(n), ans;
    iv(val);
    iv(goal);
    queue<vec> q;
    q.push({0, -1, 0, 0});
    for (int lvl = 0; !q.empty(); lvl++)
        for (int k = q.size(); k; k--)
        {
            auto node = q.front();
            int u = node[0], par = node[1], odd_xor = node[2], even_xor = node[3];
            q.pop();
            
            int curr = val[u] ^ (lvl % 2 ? odd_xor : even_xor);
            if (curr != goal[u])
            {
                if (g[u].size() > 1 || u == 0)
                    lvl % 2 ? odd_xor ^= 1 : even_xor ^= 1;
                ans.push_back(u + 1);
            }

            for (int v : g[u])
                if (v != par)
                    q.push({v, u, odd_xor, even_xor});
        }

    pl(ans.size());
    pv(ans);
    return 0;
}