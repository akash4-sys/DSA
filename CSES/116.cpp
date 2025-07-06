#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree
{
    int n;
    vector<ll> t;
public:
    SegmentTree(vector<ll> &v): n(v.size()), t(n * 2, 0)
    {
        for (int i = 0; i < n; i++)
            t[i + n] = v[i];
        for (int i = n - 1; i > 0; i--)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }

    void update(int i, ll val)
    {
        t[i += n] = val;
        while (i > 1) {
            i >>= 1;
            t[i] = t[2 * i] + t[2 * i + 1];
        }
    }

    ll query(int l, int r)
    {
        ll ans = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                ans += t[l++];
            if (r & 1)
                ans += t[--r];
        }
        return ans;
    }
};
 
int main()
{
    ll n, q, type, idx, val, l, r;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    SegmentTree seg(v);
    while (q--)
    {
        cin >> type;
        if (type == 1) {
            cin >> idx >> val;
            seg.update(idx - 1, val);
        }
        else {
            cin >> l >> r;
            cout << seg.query(l - 1, r - 1) << endl;
        }
    }
    return 0;
}