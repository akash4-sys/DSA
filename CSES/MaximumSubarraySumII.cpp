#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> pf(n + 1);
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        pf[i] += pf[i - 1] + x;
    }

    long long ans = LLONG_MIN;
    multiset<long long> st;
    for (int i = a; i <= n; i++) {
        if (i > b)
            st.erase(st.find(pf[i - b - 1]));
        st.insert(pf[i - a]);
        ans = max(ans, pf[i] - *st.begin());
    }
    cout << ans;
    return 0;
}