#include "../../headers.h"

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &v, int src, int dest)
    {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < v.size(); i++)
            for (int st : v[i])
                mp[st].push_back(i);

        unordered_set<int> visStop, visBus;
        queue<pair<int, int>> q{{{src, 0}}};
        while (!q.empty())
        {
            auto [st, dist] = q.front();
            q.pop();
            if (st == dest)
                return dist;

            visStop.insert(st);
            for (int i : mp[st])
                if (!visBus.count(i)) {
                    for (int j : v[i])
                        if (!visStop.count(j))
                            q.push({j, dist + 1});
                    visBus.insert(i);
                }
        }
        return -1;
    }
};