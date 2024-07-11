#ifdef __INTELLISENSE__
#include "../../headers.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int ssum(string &s) {
    int sum = 0;
    for (char &c : s)
        sum += (c - '0');
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    vector<int> a;
    vector<vector<int>> len(6, vector<int>(46, 0));
    for (auto &s : v) {
        cin >> s;
        a.push_back(ssum(s));
        len[s.size()][a.back()]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = v[i].size(), r = j - 1, l = 0, sf = 0, pf = 0; j > 0; j -= 2, r--, l++)
        {
            ans += len[j][max(a[i] - (pf * 2), 0)];
            if (j != v[i].size())
                ans += len[j][max(a[i] - (sf * 2), 0)];
            sf += (v[i][r] - '0');
            pf += (v[i][l] - '0');
        }
    cout << ans;
    return 0;
}