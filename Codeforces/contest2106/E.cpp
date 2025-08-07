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
    int n = II, q = II;
    vec v(n + 1), idx(n + 1);
    for (int i = 1; i <= n; i++)
        v[i] = II, idx[v[i]] = i;
    
    while (q--)
    {
        int l = II, r = II, k = II, j = idx[k];
        if (l > j || j > r) {
            pf(-1);
            continue;
        }

        int big = n - k, small = k - 1;
        int nb = 0, ns = 0, bv = big, sv = small;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (v[mid] == k) break;
            if (mid < j) {
                if (k < v[mid]) ns++;
                else sv--;
                small--;
                l = mid + 1;
            }
            else {
                if (k > v[mid]) nb++;
                else bv--;
                big--;
                r = mid - 1;
            }
        }

        if (big < 0 || small < 0) {
            pf(-1);
            continue;
        }

        int ans = min(nb, ns) * 2, d = abs(nb - ns);
        if ((nb > ns && bv < d) || (ns >= nb && sv < d))
            pf(-1);
        else pf(d * 2 + ans);
    }
    br;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}