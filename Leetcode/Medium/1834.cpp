#include "../../headers.h"

// Shortest Job First

class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        vector<int> ans, id(tasks.size());
        priority_queue<pair<int, int>> pq;
        iota(begin(id), end(id), 0);
        sort(id.begin(), id.end(), [&](const int &i, const int &j) {
            return tasks[i][0] < tasks[j][0];
        });
        
        for (long i = 0, t = 1; i < id.size() || !pq.empty();)
        {
            for (; i < id.size() && tasks[id[i]][0] <= t; i++)
                pq.push({ -tasks[id[i]][1], -id[i] });
            
            if (!pq.empty())
            {
                auto [pt, idx] = pq.top();
                pq.pop();
                t -= pt;
                ans.push_back(-idx);
            }
            else
                t = tasks[id[i]][0];
        }
        return ans;
    }
};



// Time Complexity - O(NlogN)
// Space Complexity - O(N)


struct task
{
    int id, eq, t;
};

class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &v)
    {
        auto sort_by_eq = [&](const auto &a, const auto &b) {
            return a.eq > b.eq || (a.eq == b.eq && a.t > b.t);
        };
        priority_queue<task, vector<task>, decltype(sort_by_eq)> tasks(sort_by_eq);

        auto sort_by_t = [&](const auto &a, const auto &b) {
            return a.t > b.t || (a.t == b.t && a.id > b.id);
        };
        priority_queue<task, vector<task>, decltype(sort_by_t)> avail(sort_by_t);

        long t = LLONG_MAX;
        for (int i = 0; i < v.size(); i++)
        {
            tasks.push({i, v[i][0], v[i][1]}); 
            t = min(t, (long)v[i][0]);
        }
        
        vector<int> ans;
        while (!tasks.empty() || !avail.empty())
        {
            while (!tasks.empty() && tasks.top().eq <= t)
                avail.push(tasks.top()), tasks.pop();
            if (!avail.empty())
            {
                t += avail.top().t;
                ans.push_back(avail.top().id);
                avail.pop();
            }
            else
                t = tasks.top().eq;
        }
        return ans;
    }
};



// @lc app=leetcode id=1834 lang=cpp