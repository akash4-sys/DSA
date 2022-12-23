#include "../../headers.h"

//  unordered_map is used becoz unlike most graph problems on leetcode it doesn't says that value of nodes is limited 
//  The reason i m using stack over here becoz that way we won't have to worry about having a visited array

// @ Hierholzer’s algorithm for creating eulerian cicuit  -- checking is also kind of same

class Solution
{
    void eulerianCircuit(unordered_map<int, stack<int>> &g, vector<vector<int>> &ans, int u)
    {
        auto &st = g[u];
        while (!st.empty())
        {
            int v = st.top();
            st.pop();
            eulerianCircuit(g, ans, v);
            ans.push_back({u, v});
        }
    }

public:
    vector<vector<int>> validArrangement(vector<vector<int>> &edges)
    {
        unordered_map<int, stack<int>> g;
        unordered_map<int, int> in, out;
        for (auto e : edges)
        {
            g[e[0]].push(e[1]);
            in[e[1]]++;
            out[e[0]]++;
        }
        
        int start = -1;
        for (auto [u, _] : g)
            if(out[u] == in[u] + 1)
                start = u;
        
        start = start == -1 ? g.begin()->first : start;

        vector<vector<int>> ans;
        eulerianCircuit(g, ans, start);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};