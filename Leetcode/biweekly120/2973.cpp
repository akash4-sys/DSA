#include "../../headers.h"

class Solution
{
    multiset<long long> dfs(vector<vector<int>> &g, vector<int> &cost, vector<long long> &ans, int u, int par)
    {
        multiset<long long> res = {cost[u]};
        for (int c : g[u])
            if (c != par)
            {
                auto st = dfs(g, cost, ans, c, u);
                if (st.size() <= 5)
                    for (auto it = st.rbegin(); it != st.rend(); it++)
                        res.insert(*it);
                else
                {
                    auto l = st.begin();
                    auto r = st.rbegin();
                    res.insert(*r);
                    r++;
                    for (int cnt = 0; cnt < 2; cnt++, l++, r++)
                        res.insert(*r), res.insert(*l);
                }
            }

        if (res.size() >= 3)
        {
            auto front = res.begin();
            auto back = res.rbegin();
            ans[u] = *back * (*next(back)) * (*next(next(back)));
            ans[u] = max({ans[u], *front * (*next(front)) * (*back), 0LL});
        }
        return res;
    }

public:
    vector<long long> placedCoins(vector<vector<int>> &edges, vector<int> &cost)
    {
        int n = cost.size();
        vector<vector<int>> g(n);
        for (auto &e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        vector<long long> ans(n, 1), vis(n, 0);
        dfs(g, cost, ans, 0, -1);
        return ans;
    }
};