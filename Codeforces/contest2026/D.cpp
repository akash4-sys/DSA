#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector<ll> pa, ppa, start, block, pblock;

vector<ll> prefixSum(vector<ll> &v) {
    int N = v.size();
    vector<ll> res(N + 1);
    for (int i = 0; i < N; i++)
        res[i + 1] = res[i] + v[i];
    return res;
}

ll getPartial(int l, int r1, int r2) {
    if (r2 <= r1)
        return 0LL;
    int cnt = r2 - r1;
    return ppa[r2 + 1] - ppa[r1 + 1] - (pa[l] * cnt);
}

pair<int, int> convert(long long i) {
    int j = upper_bound(start.begin(), start.end(), i) - start.begin() - 1;
    return {j, i - start[j] + j};
}

ll query(ll l, ll r) {
    auto L = convert(l);
    auto R = convert(r);
    ll res = pblock[R.first + 1] - pblock[L.first];
    if (L.second != L.first)
        res -= getPartial(L.first, L.first, L.second);
    if (R.second != n - 1)
        res -= getPartial(R.first, R.second + 1, n);
    return res;
}

int main()
{
    cin >> n;
    vector<ll> v(n);
    for (auto &a : v)
        cin >> a;
    
    pa = prefixSum(v);
    ppa = prefixSum(pa);
    start = {0};
    for (int i = n; i > 0; i--)
        start.push_back(start.back() + i);
    
    block.resize(n);
    for (int i = 0; i < n; i++)
        block[i] = getPartial(i, i, n);
    pblock = prefixSum(block);
    
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l - 1, r - 1) << "\n";
    }
    return 0;
}