#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin >> a; a; })
#define pl(x) cout << x << "\n"

ll solve()
{
    ll n = II, ans = 0, sum = 0;
    char c;
    map<ll, int> mp = {{0, 1}};
    for (int i = 1; i <= n; i++) {
        cin >> c;
        sum += (c - '0');
        ans += mp[sum - i]++;
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        pl(solve());
    return 0;
}