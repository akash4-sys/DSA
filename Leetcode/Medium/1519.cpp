#include "../../headers.h"

// Time Complexity - O(N*26)
// Space Complexity - O(N)

class Solution
{
    vector<int> ans;
    vector<int> dfs(vector<vector<int>> &g, string &s, int par, int u)
    {
        vector<int> ch(26, 0);
        for (int v : g[u])
        {
            if (par == v)
                continue;
            auto t = dfs(g, s, u, v);
            for (int i = 0; i < 26; i++)
                ch[i] += t[i];
        }

        ch[s[u] - 'a']++;
        ans[u] = ch[s[u] - 'a'];
        return ch;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string s)
    {
        vector<vector<int>> g(n);
        for (auto e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
            
        ans = vector<int>(n, 0);
        dfs(g, s, -1, 0);
        return ans;
    }
};