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

int dirs[9][2] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1},{0,0}};
int arr[3] = {-1, 0, 1};

int found(vec v, int n, int x, int y)
{
    v[0] += x;
    v[1] += y;

    int ans = (x != 0) + (y != 0), d = v[1] - v[0];
    for (int i = 2; i < n; i++)
    {
        int num = v[i - 1] + d;
        if (num != v[i] + 1 && num != v[i] - 1 && num != v[i])
            return -1;

        ans += (v[i] != num);
        v[i] = num;
    }
    return ans;
}

int solve()
{
    int n = II;
    vec v(n);
    iv(v);

    if (n <= 2)
        return 0;
    
    int ans = INT_MAX;
    for (auto di : dirs)
    {
        int x = found(v, n, di[0], di[1]);
        if (x != -1)
            ans = min(ans, x);
    }
    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    fast;
    pl(solve());
    return 0;
}