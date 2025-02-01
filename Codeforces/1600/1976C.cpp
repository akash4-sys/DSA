#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define pf(x) cout << x << " "
#define pl(x) cout << x << "\n"
#define br cout << "\n"
#define pv(v) {{ for(auto &x : v) pf(x); } br;}
#define iv(v) { for(auto &x : v) cin >> x; }

vec solve()
{
    int n = II, m = II, k = n + m + 1;
    vec a(k), b(k), c(k), hire(k, 0), wt, wp, ans(k, 0);
    iv(a);
    iv(b);

    ll sum = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] > b[i] && n)
            sum += a[i], n--, hire[i] = 1;
        else if (a[i] < b[i] && m)
            sum += b[i], m--;
        else {
            if (n) {
                sum += a[i], n--, hire[i] = 1;
                wp.push_back(i);
            }
            else {   
                sum += b[i], m--;
                wt.push_back(i);
            }
        }
        c[i] = sum;
    }
    
    for (int i = 0; i < k; i++)
        if (hire[i])
        {
            int j = lower_bound(all(wt), i) - wt.begin();
            ans[i] = sum - a[i];
            if (j == wt.size())
                continue;
            j = wt[j];
            ans[i] += hire[j] ? b[j] - a[j] : a[j] - b[j];
        }
        else
        {
            int j = lower_bound(all(wp), i) - wp.begin();
            ans[i] = sum - b[i];
            if (j == wp.size())
                continue;
            j = wp[j];
            ans[i] += hire[j] ? b[j] - a[j] : a[j] - b[j];
            if (hire[j])
                ans[i] += a[k - 1] - b[k - 1];
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