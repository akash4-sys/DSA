#include "../../headers.h"

class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &v)
    {
        int u = -1, n = v.size() + 1, par = INT_MIN;
        unordered_map<int, vector<int>> adj;
        for (auto &p : v)
        {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        for (auto &[n, vc] : adj)
            if (vc.size() == 1)
                u = n;

        vector<int> ans;
        while (ans.size() < n)
        {
            int x = u;
            ans.push_back(u);
            for (int c : adj[u])
                if (c != par)
                    u = c;
            par = x;
        }
        return ans;
    }
};