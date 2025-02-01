#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define br cout << "\n"
#define iv(v) { for(auto &x : v) cin >> x; }

class SegmentTree
{
    ll n;
    vector<ll> tree;

    ll buildTree(vec &v, int i, int left, int right)
    {
        if (left == right)
            return tree[i] = abs(v[left] - v[left - 1]);

        ll mid = left + (right - left) / 2;
        ll leftTree = buildTree(v, 2 * i, left, mid);
        ll rightTree = buildTree(v, (2 * i) + 1, mid + 1, right);
        return tree[i] = __gcd(leftTree, rightTree);
    }

public:
    SegmentTree(vec &v)
    {
        n = v.size();
        tree = vector<ll>(n * 4, 0);
        buildTree(v, 1, 1, n);
    }

    ll query(int left, int right, int i = 1, int tree_left = 1, int tree_right = -1)
    {
        if (tree_right == -1)
            tree_right = n;
        if (tree_left > right || tree_right < left)
            return 0;
        if (tree_left >= left && tree_right <= right)
            return tree[i];

        ll mid = tree_left + (tree_right - tree_left) / 2;
        ll leftTree = query(left, right, 2 * i, tree_left, mid);
        ll rightTree = query(left, right, 2 * i + 1, mid + 1, tree_right);
        return __gcd(leftTree, rightTree);
    }
};

void solve()
{
    int n = II, q = II;
    vec v(n + 1, 0);
    for (int i = 1; i <= n; i++)
        v[i] = II;

    SegmentTree tree(v);
    while (q--) {
        int l = II, r = II;
        cout << tree.query(l + 1, r) << " ";
    }
    br;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}