#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> dp;
vector<bool> used;
vector<vector<int>> sl;

int get(int v){
    if(used[v]){
        return dp[v];
    }
    used[v] = true;
    int s = 0;
    for(int u: sl[v]){
        s += get(u);
    }
    if(!sl[v].empty()) dp[v] = min(dp[v], s);
    return dp[v];
}

void solve(int tc) {
    int n, k;
    cin >> n >> k;
    dp.resize(n);
    used.assign(n, false);
    sl.assign(n, vector<int>(0));
    for(int &e: dp) cin >> e;
    for(int i = 0; i < k; ++i){
        int e;
        cin >> e;
        dp[--e] = 0;
    }
    for(int i = 0; i < n; ++i){
        int m;
        cin >> m;
        sl[i].resize(m);
        for(int &e: sl[i]){
            cin >> e;
            --e;
        }
    }
    for(int i = 0; i < n; ++i){
        get(i);
    }
    for(int e: dp) cout << e << " ";
}

bool multi = true;

signed main() {
    int t = 1;
    if(multi) cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
        cout << "\n";
    }
    return 0;
}