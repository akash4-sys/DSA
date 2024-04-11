#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// Editiorial use bezout's theorem to prove

vector<int> factors(ll x)
{
    vector<int> f;
    for (int i = 1, sq = sqrt(x); i <= sq; i++)
        if (x % i == 0) {
            if (x / i != i)
                f.push_back(x / i);
            f.push_back(i);
        }
    return f;
}

int main()
{
    fast;
    ll n;
    cin >> n;

    set<ll> st;
    for (ll k : factors(n)) {
        ll m = n / k, sum = (m * (m - 1) / 2) * k + m;
        st.insert(sum);
    }

    for (ll f : st)
        cout << f << " ";
    return 0;
}