#include "headers.h"

class Solution
{
public:
    int findCrossingTime(int n, int k, vector<vector<int>> &v)
    {
        int time = 0;
        priority_queue<pair<int, int>> lw, rw;
        set<pair<int, int>> lwh, rwh;
        for (int i = 0; i < k; i++)
            lw.push({v[i][0] + v[i][2], i});
        
        while (n || rw.size() + rwh.size())
        {
            while (!lwh.empty() && lwh.begin()->first <= time)  // STEP:4 -> push all workers who finished left warehouse job
            {
                int i = lwh.begin()->second;
                lw.push({v[i][0] + v[i][2], i});
                lwh.erase(lwh.begin());
            }

            while(!rwh.empty() && rwh.begin()->first <= time)   // STEP:2 -> push all workers who finished right warehouse job
            {
                int i = rwh.begin()->second;
                rw.push({v[i][0] + v[i][2], i});
                rwh.erase(rwh.begin());
            }

            if (!rw.empty())        // STEP:3 -> Go back to left side
            {
                int i = rw.top().second;
                rw.pop();
                time += v[i][2];
                lwh.insert({time + v[i][3], i});
            }
            else if (!lw.empty() && n)      // STEP:1 -> go to the right warehouse
            {
                int i = lw.top().second;
                lw.pop();
                --n;
                time += v[i][0];
                rwh.insert({time + v[i][1], i});
            }
            else
            {
                int x = !lwh.empty() && n ? lwh.begin()->first : INT_MAX;      // first left wh worker to get job done
                int y = !rwh.empty() ? rwh.begin()->first : INT_MAX;           // first right wh worker to get job done
                time = min(x, y);
            }
        }
        return time;
    }
};