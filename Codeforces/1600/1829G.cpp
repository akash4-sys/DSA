#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fast;
    int t, n, N = 1500;
    vector<vector<ll>> pf(N, vector<ll>(N, 0));
    ll ans[2000007] = {0};
    for (ll num = 1, k = 1; k < N; k++)
        for (ll i = k, j = 1; j < N && i > 0; i--, j++, num++) {
            pf[i][j] = num * num + pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];
            ans[num] = pf[i][j];
        }
    
    cin >> t;
    while (t--) {
        cin >> n;
        cout << ans[n] << "\n";
    }
    return 0;
}