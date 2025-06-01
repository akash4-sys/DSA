#include <bits/stdc++.h>
using namespace std;

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
    
    set<int> st;
    vector<int> ans(n, 0);
    for (auto &r : v)
        ans[r[2]] = st.lower_bound(r[0]) != st.end(), st.insert(r[0]);
    pv(ans);
        
    sort(v.begin(), v.end(), [&](auto &a, auto &b){
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    
    st.clear();
    for (auto &r : v)
        ans[r[2]] = st.lower_bound(r[1]) != st.end(), st.insert(r[1]);
    pv(ans);
    return 0;
}