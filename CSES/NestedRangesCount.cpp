#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define pv(v) {{ for(auto &x : v) cout << x << " "; } cout << endl;}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b, i});
    }

    sort(v.begin(), v.end(), [&](auto &a, auto &b){
        return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
    });
    
    ordered_set st;
    vector<int> ans(n, 0);
    for (auto &r : v) {
        ans[r[2]] = st.size() - st.order_of_key(r[0]);
        st.insert(r[0]);
    }
    pv(ans);
        
    sort(v.begin(), v.end(), [&](auto &a, auto &b){
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    
    st.clear();
    for (auto &r : v) {
        ans[r[2]] = st.size() - st.order_of_key(r[1]);
        st.insert(r[1]);
    }
    pv(ans);
    return 0;
}