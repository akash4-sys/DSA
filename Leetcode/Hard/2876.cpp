#include "../../headers.h"

class Solution
{
public:
    vector<int> countVisitedNodes(vector<int> &g)
    {
        int n = g.size();
        vector<int> ans(n, 0);
        for (int i = 0, u = 0; i < n; u = ++i)
        {
            int cycleLen = 0;
            unordered_map<int, int> dist;
            vector<int> st;
            for (int dis = 1; !dist[u] && !ans[u]; u = g[u], dis++)
            {
                st.push_back(u);
                dist[u] = dis;
                if (dist[g[u]])
                    cycleLen = dist[u] - dist[g[u]] + 1;
            }

            for (int k = 0; k < cycleLen && dist[u]; k++)
                ans[st.back()] = cycleLen, st.pop_back();

            while (!st.empty())
            {
                u = st.back();
                st.pop_back();
                ans[u] = ans[g[u]] + 1;
            }
        }
        return ans;
    }
};