#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    vector<pair<int, int>> segs(n);
    for (auto &r : segs)
        cin >> r.second >> r.first;
    sort(segs.begin(), segs.end());

    multiset<int> st;
    for (int i = 0; i < k; i++)
        st.insert(0);
    
    for (auto &r : segs) {
        auto it = st.upper_bound(r.second);
        if (it == st.begin())
            continue;
        st.erase(--it);
        st.insert(r.first);
        ans++;
    }
    cout << ans;
    return 0;
}