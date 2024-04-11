#include "../../headers.h"

#define vec vector<vector<pair<int, int>>>

class Solution
{
public:
    vector<int> minimumCost(int n, vector<vector<int>> &v, vector<vector<int>> &q)
    {
        int m = q.size();
        if (v.size() == 0)
            return vector<int>(m, 0);
        
        vector<int> col(n, 0), mp(n, INT_MAX);
        vec g(n);
        for (auto &r : v) {
            g[r[0]].push_back({r[1], r[2]});
            g[r[1]].push_back({r[0], r[2]});
            mp[r[0]] &= r[2];
            mp[r[1]] &= r[2];
        }

        function<int(int, int)> dfs = [&](int i, int c) -> int {
            col[i] = c;
            int res = mp[i];
            for (auto [cd, w] : g[i])
                if (!col[cd])
                    res &= dfs(cd, c);
            return res;
        };

        vector<int> colmp(n + 1, INT_MAX), ans;
        for (int i = 0, c = 1; i < n; i++)
            if (!col[i]) {
                int cost = dfs(i, c);
                cost = cost == INT_MAX ? 0 : cost;
                colmp[c] = cost;
                c++;
            }

        for (auto &r : q) {
            int cost = col[r[0]] != col[r[1]] ? -1 : (r[0] == r[1] ? 0 : (colmp[r[1]]));
            ans.push_back(cost);
        }
        return ans;
    }
};