#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vv vector<vec>
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })
#define SS ({ string s; cin>>s; s; })
#define pf(x) cout << x << " "

struct Node {
    ll fq[2] = {0, 0};

    void add(int x, ll val, int len) {
        fq[x] += val * len;
    }

    void merge(const Node& left, const Node& right) {
        fq[0] = left.fq[0] + right.fq[0];
        fq[1] = left.fq[1] + right.fq[1];
    }
};

struct Lazy {
    ll add[2] = {0, 0};

    bool empty() const {
        return add[0] == 0 && add[1] == 0;
    }

    void clear() {
        add[0] = add[1] = 0;
    }
};

class LazySegmentTree {
    int n;
    vector<Node> tree;
    vector<Lazy> lazy;

public:
    LazySegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }

    void push(int i, int tl, int tr) {
        if (lazy[i].empty()) return;
        int len = tr - tl + 1;

        for (int x = 0; x < 2; ++x) {
            tree[i].add(x, lazy[i].add[x], len);
        }

        if (tl != tr) {
            for (int x = 0; x < 2; ++x) {
                lazy[i * 2].add[x] += lazy[i].add[x];
                lazy[i * 2 + 1].add[x] += lazy[i].add[x];
            }
        }

        lazy[i].clear();
    }

    void update(int l, int r, int x, ll val = 1, int i = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        push(i, tl, tr);
        if (l > r || r < tl || tr < l) return;

        if (l <= tl && tr <= r) {
            lazy[i].add[x] += val;
            push(i, tl, tr);
            return;
        }

        int mid = (tl + tr) / 2;
        update(l, r, x, val, i * 2, tl, mid);
        update(l, r, x, val, i * 2 + 1, mid + 1, tr);
        tree[i].merge(tree[i * 2], tree[i * 2 + 1]);
    }

    ll query(int l, int r, int i = 1, int tl = 0, int tr = -1) {
        if (tr == -1) tr = n - 1;
        push(i, tl, tr);
        if (l > r || r < tl || tr < l) return 0;

        if (tl == tr)
            return max(tree[i].fq[0], tree[i].fq[1]);
        int mid = (tl + tr) / 2;
        return query(l, r, i * 2, tl, mid) + query(l, r, i * 2 + 1, mid + 1, tr);
    }
};


ll solve()
{
    int n = II;
    string s = SS;
    ll ans = 0;
    LazySegmentTree tree(n);
    for (int i = 0; i < n; i++) {
        tree.update(0, i, s[i] - '0');
        ans += tree.query(0, i);
    }
    return ans;
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        cout << solve() << "\n";
    return 0;
}