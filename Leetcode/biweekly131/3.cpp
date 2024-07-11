#include "../../headers.h"

class Solution
{
public:
    vector<int> queryResults(int n, vector<vector<int>> &qrs)
    {
        vector<int> ans;
        unordered_map<int, int> ball;
        unordered_map<int, set<int>> col;
        for (auto &q : qrs)
        {
            if (ball.count(q[0]))
            {
                int c = ball[q[0]];
                col[c].erase(col[c].find(q[0]));
                if (col[c].empty())
                    col.erase(c);
            }
            ball[q[0]] = q[1];
            col[q[1]].insert(q[0]);
            ans.push_back(col.size());
        }
        return ans;
    }
};