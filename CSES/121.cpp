#ifdef __INTELLISENSE__
#include "../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define ll long long

struct Vertex {
    ll val, it;
};

int n, m, q;
Vertex t[800004];

Vertex Max(Vertex &a, Vertex &b) {
    return a.val >= b.val ? a : b;
}

void build(vector<ll> &v, int i = 1, int l = 0, int r = -1)
{
    if (r == -1)
        r = n - 1;
    
    if (l == r)
    {
        t[i] = {v[l], l + 1};
        return;
    }

    int mid = (l + r) / 2;
    build(v, i * 2, l, mid);
    build(v, i * 2 + 1, mid + 1, r);
    t[i] = Max(t[i * 2], t[i * 2 + 1]);
}

int query(int val, int i = 1, int l = 0, int r = -1)
{
    if (r == -1)
        r = n - 1;
    if (t[i].val < val)
        return 0;
    if (l == r)
    {
        t[i].val -= val;
        return t[i].it;
    }

    int mid = (l + r) / 2;
    int it = (t[i * 2].val >= val) ?  query(val, i * 2, l, mid) : query(val, i * 2 + 1, mid + 1, r);
    t[i] = Max(t[i * 2], t[i * 2 + 1]);
    return it;
}

int main()
{
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    build(v);
    while (m--)
    {
        cin >> q;
        cout << query(q) << " ";
    }
    return 0;
}