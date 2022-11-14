#include "../../headers.h"

class Solution
{
    unordered_map<int, int> mp;
    int islands = 0;
    int find(int x)
    {
        if(!mp.count(x))
            mp[x] = x, islands++;
        if(x != mp[x])
            mp[x] = find(mp[x]);
        return mp[x];
    }

    void unionFind(int x, int y)
    {
        x = find(x), y = find(y);
        if(x != y)
            mp[x] = y, islands--;
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        for(auto s: stones)
            unionFind(s[0], -(s[1] + 1));
        return stones.size() - islands;
    }
};



class Solution
{
    int dfs(vector<vector<int>> &v, vector<int> &vis, int id)
    {
        vis[id] = 1;
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
            if (!vis[i] && (v[i][0] == v[id][0] || v[i][1] == v[id][1]))
                ans += dfs(v, vis, i) + 1;
        return ans;
    }

public:
    int removeStones(vector<vector<int>> &v)
    {
        vector<int> vis(v.size(), 0);
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
            if (!vis[i])
                ans += dfs(v, vis, i);
        return ans;
    }
};