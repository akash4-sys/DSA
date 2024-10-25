#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
void solve() {
    cin >> n >> m;
    ll allSum = 0;
    vector<ll> pref, ind;
	for (int i = 0; i < n; i++) {
		int e;
        cin >> e;
        allSum += e;
        if (pref.empty() || allSum > pref.back()) {
            pref.push_back(allSum);
            ind.push_back(i);
        }
    }

    for (int q = 0; q < m; q++) {
        ll x;
        cin >> x;
        if (pref.back() < x && allSum <= 0) {
            cout << -1 << " ";
            continue;
        }

        ll needTimes = 0;
        if (pref.back() < x)
            needTimes = (x - pref.back() + allSum - 1) / allSum;
        x -= needTimes * allSum;
        cout << needTimes * n + ind[lower_bound(pref.begin(), pref.end(), x) - pref.begin()]<< " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}