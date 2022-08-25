#include "../../headers.h"

class Solution
{
public:
    int minJumps(vector<int> &v)
    {
        int ans = 0, n = v.size();
        unordered_map<int, vector<int>> ump;
        vector<bool> vis(n, false);
        queue<int> q;

        for (int i = 0; i < n; i++)
            ump[v[i]].push_back(i);

        q.push(0);
        vis[0] = true;

        while (!q.empty())
        {
            int c = q.size();
            while (c--)
            {
                int x = q.front();
                q.pop();
                if (x == n - 1)
                    return ans;
                vector<int> l = ump[v[x]];
                l.push_back(x - 1);
                l.push_back(x + 1);
                for (int i : l)
                    if (i >= 0 && i < n && !vis[i])
                        vis[i] = true, q.push(i);
                ump.erase(v[x]);
            }
            ans++;
        }
        return 0;
    }
};