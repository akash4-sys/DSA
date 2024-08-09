#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

ll solve()
{
    ll n = II, k = II, ans = 0, m = 0;
    vector<ll> a(n);
    for (ll &x : a)
        x = II, m = max(m, x);
    
    ll l = 0, r = m + k;
    while (l <= r)
    {
        ll mid = (l + r) / 2, flag = 0;
        for (int i = 0; i < n && !flag; i++)
        {
            ll x = mid, op = 0;
            for (int j = i; j < n; j++) {
                if (x <= a[j])
                    break;
                if (j + 1 == n) {
                    op = k + 1;
                    break;
                }
                op += x - a[j];
                x = max(x - 1, 0LL);
            }
            if (op <= k)
                flag = 1;
        }
        if (flag)
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}