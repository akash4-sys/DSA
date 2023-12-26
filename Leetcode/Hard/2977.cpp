#include "../../headers.h"

#define ll long long
#define MAX 1e11

class Solution
{
    ll dp[1001];
    unordered_map<string, int> mp;
    unordered_set<int> st;

    void floydWarshall(vector<vector<ll>> &dist)
    {
        int n = dist.size();
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n && dist[i][k] < MAX; j++)
                    if (dist[k][j] < MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    ll rec(string &src, string &target, vector<vector<ll>> &dist, int i)
    {
        if (i >= src.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];

        ll res = MAX;
        if (src[i] == target[i])
            res = rec(src, target, dist, i + 1);

        for (int k : st)
            if (i + k <= src.size())
            {
                string subSrc = src.substr(i, k);
                string subTg = target.substr(i, k);
                int l1 = mp.count(subSrc) ? mp[subSrc] : -1;
                int l2 = mp.count(subTg) ? mp[subTg] : -1;
                if (l1 >= 0 && l2 >= 0 && dist[l1][l2] < MAX)
                    res = min(res, rec(src, target, dist, i + k) + dist[l1][l2]);
            }
        return dp[i] = res;
    }

    void mapper(vector<string> &v)
    {
        for (auto &s : v)
            if (!mp.count(s))
                mp[s] = mp.size();
    }

public:
    ll minimumCost(string src, string target, vector<string> &a, vector<string> &b, vector<int> &cost)
    {
        mapper(a);
        mapper(b);

        int n = mp.size();
        vector dist(n, vector<ll>(n, MAX));
        for (int i = 0; i < a.size(); i++)
            dist[mp[a[i]]][mp[b[i]]] = min(dist[mp[a[i]]][mp[b[i]]], (ll)cost[i]);

        floydWarshall(dist);
        for (auto &s : a)
            st.insert(s.size());

        memset(dp, -1, sizeof(dp));
        ll ans = rec(src, target, dist, 0);
        return ans == MAX ? -1 : ans;
    }
};