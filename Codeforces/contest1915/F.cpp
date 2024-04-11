#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

long long solve()
{
    int n = II;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({II, II});
    
    sort(v.begin(), v.end(), [&](auto &a, auto &b) {
        return a[1] < b[1];
    });

    long long ans = 0;
    ordered_set st;
    for (auto &p : v) {
        st.insert(p[0]);
        ans += (st.size() - st.order_of_key(p[0]) - 1);
    }
    return ans;
}

int main()
{
    fast;
    int tc = II;
    while (tc--)
        cout << solve() << "\n";
    return 0;
}