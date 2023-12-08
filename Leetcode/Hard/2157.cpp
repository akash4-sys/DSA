#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    unordered_map<int, int> g;
    int genMask(string &s)
    {
        int mask = 0;
        for (char &c : s)
            mask |= 1 << (c - 'a');
        return mask;
    }

    int dfs(int mask)
    {
        int res = 0;
        if (auto it = g.find(mask); it != g.end())
        {
            res += it->second;
            g.erase(it);
            for (int i = 0; i < 26; i++)
            {
                res += dfs(mask ^ (1 << i));
                for (int j = i + 1; j < 26; j++)
                    if (((mask >> i) & 1) != ((mask >> j) & 1))
                        res += dfs(mask ^ (1 << i) ^ (1 << j));
            }
        }
        return res;
    }

public:
    vector<int> groupStrings(vector<string> &v)
    {
        int cnt = 0, mx = 0, n = v.size();
        for (int i = 0; i < n; i++)
            g[genMask(v[i])]++;
        
        while (g.size())
            mx = max(mx, dfs(g.begin()->first)), cnt++;
        return {cnt, mx};
    }
};



// Time Complexity - O(N*26*26)
// Space Complexity - O(N)

class Solution
{
    vector<int> masks;
    unordered_map<int, vector<int>> g;

    int genMask(string &s)
    {
        int mask = 0;
        for (char &c : s)
            mask |= 1 << (c - 'a');
        return mask;
    }

    int dfs(vector<int> &vis, int u)
    {
        vis[u] = 1;
        int res = 1;
        for (int i = 0; i < 26; i++)
        {
            int mask = i < 26 ? masks[u] ^ (1 << i) : masks[u];
            if (g.count(mask))
                for (int v : g[mask])
                    res += vis[v] ? 0 : dfs(vis, v);
            
            if (masks[u] & (1 << i))
            {
                for (int j = 0; j < 26; j++)
                    if (i != j)
                    {
                        mask = (masks[u] ^ (1 << i)) | (1 << j);
                        if (g.count(mask))
                            for (int v : g[mask])
                                res += vis[v] ? 0 : dfs(vis, v);
                    }
            }
        }
        return res;
    }

public:
    vector<int> groupStrings(vector<string> &v)
    {
        int cnt = 0, mx = 0, n = v.size();
        for (int i = 0; i < n; i++)
        {
            masks.push_back(genMask(v[i]));
            g[masks.back()].push_back(i);
        }
        
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
            if (!vis[i])
                mx = max(dfs(vis, i), mx), cnt++;
        return {cnt,  mx};
    }
};

// @lc app=leetcode id=2157 lang=cpp