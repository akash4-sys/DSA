#include "../../headers.h"

//  The reason i m using stack over here becoz that way we won't have to worry about having a visited array

// @ Hierholzer’s algorithm for creating eulerian cicuit  -- checking is also kind of same

class Solution
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &edges)
    {
        map<int, vector<int>> g;
        map<int, int> in, out;
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            in[e[1]]++, out[e[0]]++;
        }
        
        int start = -1;
        for (auto &[u, vec] : g)
            if(out[u] - in[u] == 1) {
                start = u;
                break;
            }
        
        vector<vector<int>> ans;
        auto dfs = [&](auto &&dfs, int u) -> void {
            while (!g[u].empty())
            {
                int v = g[u].back();
                g[u].pop_back();
                dfs(dfs, v);
                ans.push_back({u, v});
            }
        };
        dfs(dfs, start == -1 ? g.begin()->first : start);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};