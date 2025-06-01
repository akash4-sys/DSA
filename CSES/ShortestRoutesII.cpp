#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long MAX = 1e15;

void floydWarshall(int n, vector<vector<long long>>& dist) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dist[i][k] < MAX) {
                for (int j = 0; j < n; ++j) {
                    if (dist[k][j] < MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> dist(n, vector<long long>(n, MAX));

    for (int i = 0; i < n; ++i)
        dist[i][i] = 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        --u; --v;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    floydWarshall(n, dist);

    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (dist[u][v] < MAX) {
            cout << dist[u][v] << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}