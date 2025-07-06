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

void Sort(vv &ans, vec &v, int k = 1){
    int n = v.size(), swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                ans.push_back({k, j  + 1});
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
};

void solve()
{
    int n = II;
    vec a(n), b(n);
    iv(a); iv(b);
    vv ans;
    Sort(ans,  a, 1);
    Sort(ans,  b, 2);
    for (int i = 0; i <n; i++)
        if (a[i] > b[i]) {
            ans.push_back({3, i  + 1});
            swap(a[i], b[i]);
        }
    
    pl(ans.size());
    pvv(ans);
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}