#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define II ({ int a; cin>>a; a; })

void solve()
{
    int n = II, two = 0, neg = 0, prod = -1, x = -1, y = -1;
    vector<int> v(n + 1, 0), cnt2 = {0}, cntN = {0}, idx = {0};
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        neg += v[i] < 0;
        two += abs(v[i]) == 2;
        cnt2.push_back(two);
        cntN.push_back(neg);
        if (!v[i])
            idx.push_back(i);
    }

    v.push_back(0);
    cnt2.push_back(cnt2.back());
    cntN.push_back(cntN.back());
    idx.push_back(n + 1);

    for (int i = 1; i < idx.size(); i++)
    {
        int l = idx[i - 1], r = idx[i];
        neg = cntN[r] - cntN[l];
        two = cnt2[r] - cnt2[l];
        if (neg % 2 == 0 && two >= prod)
            prod = two, x = idx[i - 1], y = idx[i];
        
        if (neg % 2)
        {
            for (; v[l] >= 0; l++);
            if ((two = cnt2[r] - cnt2[l]) >= prod)
                prod = two, x = l, y = r;
            for (; v[r] >= 0; r--);
            if ((two = cnt2[r - 1] - cnt2[idx[i - 1]]) >= prod)
                prod = two, x = idx[i - 1], y = r;
        }
    }
    cout << x << " " << n - y + 1 << "\n";
}

int main()
{
    fast;
    for (int tc = II; tc; tc--)
        solve();
    return 0;
}