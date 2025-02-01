// Author : pandastic

#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define iv(v) { for(auto &x : v) cin >> x; }

vector<long long> inversion(30, 0), anti_inversion(30, 0);
vector<vector<int>> v;

void solve(vector<int> &idx, int j)
{
    int c0 = 0, c1 = 0;
    vector<int> zero, one;
    for (int i = 0; i < idx.size(); i++)
        if (v[idx[i]][j]) {
            one.push_back(idx[i]);
            anti_inversion[j] += c0;
            c1++;
        }
        else {
            zero.push_back(idx[i]);
            inversion[j] += c1;
            c0++;
        }
    
    if (j && c0)
        solve(zero, j - 1);
    if (j && c1)
        solve(one, j - 1);
}

int main()
{
    fast;
    int n;
    cin >> n;
    vector<int> a(n), idx(30);
    iv(a);
    v.resize(n, vector<int>(30, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 30; j++)
            if (a[i] & (1 << j))
                v[i][j] = 1;
    
    iota(idx.begin(), idx.end(), 0);
    solve(idx, 29);

    int minInv = 0, x = 0;
    for (int i = 29; i >= 0; i--) {
        x <<= 1;
        if (inversion[i] > anti_inversion[i])
            minInv += anti_inversion[i], x++;
        else
            minInv += inversion[i];
    }
    cout << minInv << " " << x;
    return 0;
}