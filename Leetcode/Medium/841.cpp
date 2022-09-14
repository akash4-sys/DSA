#include "../../headers.h"

// Time Complexity - O(V + E+ N)
// Space Complexity - O(N)

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<int> vis(rooms.size(), 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int k : rooms[v])
                if (!vis[k])
                    q.push(k), vis[k] = 1;
        }
        for (int i : vis)
            if (!i)
                return false;
        return true;
    }
};




class Solution
{
    void dfs(vector<vector<int>>& rooms, vector<int>& vis, int v)
    {
        vis[v] = 1;
        for(int k: rooms[v])
            if(!vis[k])
                dfs(rooms, vis, k);
    }

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<int> vis(rooms.size(), 0);
        dfs(rooms, vis, 0);
        for (int i : vis)
            if (!i)
                return false;
        return true;
    }
};