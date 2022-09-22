#include "../../headers.h"

class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int t, int ch)
    {
        using p = pair<int, int>;
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<int>> g(n + 1), time(n + 1);

        for (auto e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        pq.push({0, 1});
        time[1].push_back(0);

        while (!pq.empty())
        {
            auto [tm, v] = pq.top();
            pq.pop();
            if (v == n && time[n].size() == 2)
                return time[n][1];

            for (auto c : g[v])
            {
                int curr_time = ((tm / ch) % 2 ? (tm / ch + 1) * ch : tm) + t;
                if (time[c].empty() || (time[c].size() == 1 && time[c].front() != curr_time))
                    pq.push({ curr_time, c }), time[c].push_back(curr_time);
            }
        } 
        return 0;
    }
};