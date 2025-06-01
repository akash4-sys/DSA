#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
struct E{
    int v, w;
};
array<vector<E>, 2504> G, B;
array<bool, 2504> gis, bis;
array<int, 2504> dis, cnt;
void gfs(int u){
    gis[u] = 1;
    for(auto [v, w] : G[u]){
        if(!gis[v]) gfs(v);
    }
}
void bfs(int u){
    bis[u] = 1;
    for(auto [v, w] : B[u]){
        if(!bis[v]) bfs(v);
    }
}
int run(int s, int t){
    int u;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(auto [v, w] : G[u]){
            if(cnt[v] > t) continue;
            if(dis[u] + w > dis[v]){
                Q.push(v);
                dis[v] = dis[u] + w;
                cnt[v]++;
                if(cnt[v] > t && gis[v] && bis[v]) return -1;
            }
        }
    }
    return dis[t];
}
signed main(){
    int n, m, a, b, x;
    cin >> n >> m;
    for(int i = 2; i <= n; i++) dis[i] = -1e18;
    while(m--){
        cin >> a >> b >> x;
        G[a].pb({b, x});
        B[b].pb({a, x});
    }
    gfs(1);
    bfs(n);
    cout << run(1, n);
    return 0;
}