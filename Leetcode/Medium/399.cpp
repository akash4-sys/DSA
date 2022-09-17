#include "../../headers.h"

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &eq, vector<double> &v, vector<vector<string>> &queries)
    {
        unordered_map<string, vector<pair<string, double>>> g;
        for (int i = 0; i < v.size(); i++)
            g[eq[i][0]].push_back({eq[i][1], v[i]}), g[eq[i][1]].push_back({eq[i][0], 1 / v[i]});

        vector<double> ans;
        for (auto qry : queries)
        {
            if (g.find(qry[0]) == g.end() || g.find(qry[1]) == g.end())
            {
                ans.push_back(-1);
                continue;
            }

            int notfound = 1;
            queue<pair<string, double>> q;
            unordered_set<string> vis;
            q.push({qry[0], 1});
            vis.insert(qry[0]);

            while (!q.empty())
            {
                auto [v, w] = q.front();
                q.pop();
                if (v == qry[1])
                {
                    ans.push_back(w);
                    notfound = 0;
                    break;
                }
                for (auto [c, cw] : g[v])
                    if (vis.find(c) == vis.end())
                        q.push({c, w * cw}), vis.insert(c);
            }
            if (notfound)
                ans.push_back(-1);
        }
        return ans;
    }
};