#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define vec vector<int>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << endl
#define br cout << endl
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define iv(v) { for(auto &x : v) cin >> x; }

vec f(vec &v, int x, int y)
{
    int n = v.size();
    if (x > y)
        return {n, 0, 0};
    
    int two = 0, neg = 0;
    for (int i = x; i <= y; i++)
        neg += (v[i] < 0), two += (abs(v[i]) == 2);
    if (neg % 2 == 0)
        return {x, n - y - 1, two};
    
    vec res;
    for (int i = x, k = 1, c = 0; i <= y && k; i++)
    {
        c += abs(v[i]) == 2;
        if (v[i] < 0)
            res = {i + 1, n - y - 1, two - c}, k = 0;
    }
    
    for (int i = y, k = 1, c = 0; i >= x && k; i--)
        if (v[i] < 0)
        {
            c += abs(v[i]) == 2;
            if (v[i] < 0) {
                if (res.back() < two - c)
                    res = {x, n - i, two - c};
                k = 0;
            }
        }
    return res;
}

vec solve()
{
    int n = II, j = 0;
    vec v(n), ans = {n, 0, 0};
    iv(v);
    if (count(all(v), 0) == 0) {
        vec res = f(v, 0, n - 1);
        res.pop_back();
        return res;
    }
    
    for (int i = 0; i < n; i++)
        if (v[i] == 0) {
            vec res = f(v, j, i - 1);
            if (res.back() > ans.back())
                ans = res;
            j = i + 1;
        }
    
    vec res = f(v, j, v.size() - 1);
    if (res.back() > ans.back())
        ans = res;
    ans.pop_back();
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