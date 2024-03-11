#include "../../headers.h"

class Solution
{
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int k)
    {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        function<int(int, int, int)> dfs = [&](int u, int par, int dist) {
            int res = dist % k == 0;
            for (auto [v, w] : adj[u])
                if (v != par)
                    res += dfs(v, u, dist + w);
            return res;
        };

        vector<int> ans(n, 0);
        for (int u = 0; u < n; u++) {
            int nodes = 0;
            for (auto &[v, w] : adj[u]) {
                int cnt = dfs(v, u, w);
                ans[u] += (nodes * cnt);
                nodes += cnt;
            }
        }
        return ans;
    }
};