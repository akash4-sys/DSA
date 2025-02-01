#include <bits/stdc++.h>
using namespace std;

#define vec vector<int>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define iv(v) { for(auto &x : v) cin >> x; }

int limit = 1e9;

vec solve()
{
    int n = II;
    vec a(n), v;
    iv(a);
    for (int i = 0; i < n; i++)
        if (a[i] >= 0)
            v.push_back(i);
    
    for (int i = 1; i < v.size(); i++) {
        int l = v[i - 1], r = v[i];
        while (r - l > 1)
            if (a[l] >= a[r]) {
                if (a[l] / 2 > 0)
                    a[l + 1] = a[l] / 2;
                else
                    a[l + 1] = a[l] * 2;
                l++;
            }
            else {
                if (a[r] / 2 > 0)
                    a[r - 1] = a[r] / 2;
                else
                    a[r - 1] = a[r] * 2;
                r--;
            }
    }

    if (v.empty())
        v.push_back(0), a[0] = 1;

    if (v.size() && v[0] != 0)
        for (int i = v[0] - 1; i >= 0; i--)
            if (a[i + 1] * 2LL > limit)
                a[i] = a[i + 1] / 2;
            else
                a[i] = a[i + 1] * 2;
    
    if (v.size() && v.back() != n - 1)
        for (int i = v.back() + 1; i < n; i++)
            if (a[i - 1] * 2LL > limit)
                a[i] = a[i - 1] / 2;
            else
                a[i] = a[i - 1] * 2;
    
    for (int i = 0; i < n; i++)
        if (i + 1 < n && a[i] != a[i + 1] / 2 && a[i + 1] != a[i] / 2)
            return {-1};
    return a;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pv(solve());
    return 0;
}