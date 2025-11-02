#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int TWO_MOD_INV = 500000004;

long long total_sum(long long start, long long end) {
	return ((((end - start + 1) % MOD) * ((start + end) % MOD) % MOD) * TWO_MOD_INV %
	        MOD);
}

int main() {
	long long n;
	cin >> n;
	long long ans = 0;
	long long at = 1;
	while (at <= n) {
		long long add_amt = n / at;
		long long last_same = n / add_amt;
		ans = (ans + add_amt * total_sum(at, last_same)) % MOD;
		at = last_same + 1;
	}
	cout << ans << endl;
}