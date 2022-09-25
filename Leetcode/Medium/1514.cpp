#include "../../headers.h"
// @lc app=leetcode id=1514 lang=cpp

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &e, vector<double> &succ, int s, int dest)
    {
        vector<vector<pair<int, double>>> g(n);
        vector<double> prob(n, INT_MIN); 
        vector<int> vis(n, 0);
        priority_queue<pair<double, int>> pq;

        for(int i = 0; i < e.size(); i++)
            g[e[i][0]].push_back({e[i][1], succ[i]}), g[e[i][1]].push_back({e[i][0], succ[i]});
        pq.push({1.0, s});
        prob[s] = 1.0;

        while(!pq.empty())
        {
            auto [p, v] = pq.top();
            pq.pop();
            vis[v] = 1;
            if(p > prob[v])
                continue;
            for(auto &[c, cp]: g[v])
                if(!vis[c] && p * cp > prob[c])
                    prob[c] = p * cp, pq.push({prob[c], c});
        }
        return prob[dest] == INT_MIN ? 0 : prob[dest];
    }
};

