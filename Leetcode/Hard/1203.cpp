#include "../../headers.h"

// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
    vector<int> topoSort(vector<unordered_set<int>> &adj, vector<int> &deg)
    {
        vector<int> res;
        queue<int> q;
        for (int u = 0; u < deg.size(); u++)
            if (!deg[u])
                q.push(u);
        
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (auto &v : adj[u])
                if (--deg[v] == 0)
                    q.push(v);
        }
        return res;
    }

public:
    vector<int> sortItems(int n, int m, vector<int> &grp, vector<vector<int>> &bi)
    {
        for (int &g : grp)
            if (g == -1)
                g = m++;
        
        vector<unordered_set<int>> grpAdj(m), itemAdj(n);
        vector<int> grpDeg(m), itemDeg(n);
        for (int i = 0; i < n; i++)
            for (int &u : bi[i])
            {
                if (grp[i] != grp[u] && !grpAdj[grp[u]].count(grp[i])) {
                    grpAdj[grp[u]].insert(grp[i]);
                    grpDeg[grp[i]]++;
                }
                else if (!itemAdj[u].count(i)) {
                    itemAdj[u].insert(i);
                    itemDeg[i]++;
                }
            }
        
        vector<int> sortGrp = topoSort(grpAdj, grpDeg), sortItem = topoSort(itemAdj, itemDeg);
        vector grpItems(m, vector<int>());
        for (int &u : sortItem)
            grpItems[grp[u]].push_back(u);
        
        vector<int> ans;
        for (int grpId : sortGrp)
            for (int &u : grpItems[grpId])
                ans.push_back(u);
        return ans.size() == n ? ans : vector<int>();
    }
};