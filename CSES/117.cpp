#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree {
    int n;
    vector<int> t;
public:
    SegmentTree(int N): n(N), t(N * 2 + 1, INT_MAX) {}

    void update(int i, int val) {
        t[i += n] = val;
        while (i > 1) {
            i >>= 1;
            t[i] = min(t[i << 1], t[i << 1 | 1]);
        }
    }

    int query(int l, int r) {
        int ans = INT_MAX;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                ans = min(ans, t[l++]);
            if (r & 1)
                ans = min(ans, t[--r]);
        }
        return ans;
    }
};


int main()
{
    ll n, q, type, idx, val, l, r;
    cin >> n >> q;
    vector<ll> v(n);
    SegmentTree tree(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        tree.update(i, v[i]);
    }

    while (q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> idx >> val;
            tree.update(idx - 1, val);
        }
        else
        {
            cin >> l >> r;
            cout << tree.query(l - 1, r - 1) << endl;
        }
    }
    return 0;
}