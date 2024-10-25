#include <bits/stdc++.h>
using namespace std;

#define vec vector<int>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define LL ({ ll a; cin>>a ; a; })
#define pf(x) cout << x << " "
#define br cout << "\n"
#define pyn(x) cout << (x ? "YES" : "NO") << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define pvv(mat) { for(auto &r : mat) pv(r); }

vec solve()
{
    int n = II, u = -1;
    vector<int> h(n), w(n);
    for (int i = 0; i < n; i++) {
        h[i] = II, w[i] = II;
        if (h[i] > w[i])
            swap(h[i], w[i]);
    }

    vec ans(n, -1), idx(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j){
        return h[i] < h[j];
    });

    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && h[idx[i]] == h[idx[j]])
            j++;

        for (int k = i; k < j; k++)
            if (u != -1 && w[u] < w[idx[k]])
                ans[idx[k]] = u + 1;
        
        for (int k = i; k < j; k++)
            if (u == -1 || w[u] > w[idx[k]])
                u = idx[k];
        i = j;
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}