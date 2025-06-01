#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const ll MOD = (10e8) + 7;
int main()
{
	int n, m;
	cin >> n >> m;
	int v[n];
	for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<ll> dp1(m + 1, 0), dp2(m + 1, 0);
    if (v[0] == 0)
        fill(dp1.begin(), dp1.end(), 1);
    else
        dp1[v[0]] = 1;

	for (int i = 1; i < n; i++)
    {
		if (v[i] == 0)
        {
			for (int j = 1; j <= m; j++) {
				dp2[j] += dp1[j];
				if (j - 1 > 0) dp2[j] += dp1[j - 1];
				if (j + 1 <= m) dp2[j] += dp1[j + 1];
				dp2[j] %= MOD;
			}
		} else {
			dp2[v[i]] += dp1[v[i]];
			if (v[i] - 1 > 0) dp2[v[i]] += dp1[v[i] - 1];
			if (v[i] + 1 <= m) dp2[v[i]] += dp1[v[i] + 1];
			dp2[v[i]] %= MOD;
		}
        dp1 = dp2;
        fill(dp2.begin(), dp2.end(), 0);
	}

	ll ans = 0;
	for (int i = 1; i <= m; i++)
		ans = (ans + dp1[i]) % MOD;
	cout << ans;
}