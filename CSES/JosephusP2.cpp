#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    fast;
    int n, k;
    cin >> n >> k;
    ordered_set st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    
    int i = k % n;
    while  (n--) {
        auto x = st.find_by_order(i);
        cout << *x << " ";
        st.erase(x);
        if (n)
            i = (i % n + k) % n;
    }
    return 0;
}