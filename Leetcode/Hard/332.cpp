#include "../../headers.h"

#define mp unordered_map<string, priority_queue<string, vector<string>, greater<string> >>

// @ euclerian circuit

class Solution
{
    void eulerianCircuit(mp &g, vector<string> &ans, string u)
    {
        auto &pq = g[u];
        while (!pq.empty())
        {
            auto v = pq.top();
            pq.pop();
            eulerianCircuit(g, ans, v);
        }
        ans.push_back(u);
    }

public:
    vector<string> findItinerary(vector<vector<string>> &edges)
    {
        mp g;
        for (auto &e : edges)
            g[e[0]].push(e[1]);
        
        vector<string> ans;
        eulerianCircuit(g, ans, "JFK");
        return vector<string>(ans.rbegin(), ans.rend());
    }
};


// @lc app=leetcode id=332 lang=cpp