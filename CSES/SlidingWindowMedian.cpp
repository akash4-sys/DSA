#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    multiset<int> st;
    vector<int> v(n);
    for (int &a : v) {
        cin >> a;
        if (st.size() < k)
            st.insert(a);
    }

    auto med = next(st.begin(), k % 2 == 0 ? (k / 2) - 1 : (k / 2));
    cout << *med << " ";
    for (int i = 1; i <= n - k; i++) {
        st.insert(v[i + k - 1]);
        if (v[i + k - 1] < *med)
            med--;
        if (v[i - 1] <= *med)
            med++;
        st.erase(st.lower_bound(v[i - 1]));
        cout << *med << " ";
    }
    return 0;
}