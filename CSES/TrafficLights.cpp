#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, maxGap = 0, last = 0;
    cin >> n >> q;
    set<int> st = {0, n};
    vector<int> v(q), gaps(q);
    for (int &p : v) {
        cin >> p;
        st.insert(p);
    }

    for (int p : st)
        maxGap = max(maxGap, p - last), last = p;
    for (int i = q - 1; i >= 0; i--) {
        gaps[i] = maxGap;
        st.erase(v[i]);
        auto it = st.lower_bound(v[i]);
        maxGap = max(maxGap, *it - *prev(it));
    }
    
    for (auto &gap : gaps)
        cout << gap << " ";
    return 0;
}