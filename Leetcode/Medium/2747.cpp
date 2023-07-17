#include "../../headers.h"

class Solution
{
public:
    vector<int> countServers(int n, vector<vector<int>> &v, int x, vector<int> &qrs)
    {
        vector<int> ans(qrs.size(), 0);
        sort(v.begin(), v.end(), [&](auto &a, auto &b){
            return a[1] < b[1];
        });

        vector<vector<int>> qi;
        for (int i = 0; i < qrs.size(); i++)
            qi.push_back({qrs[i], i});
        sort(qi.begin(), qi.end());

        int i = 0, j = 0;
        unordered_map<int, int> mp;
        for (auto q : qi)
        {
            int st = max(0, q[0] - x), en = q[0];
            for (; j < v.size() && v[j][1] <= en; j++)
                mp[v[j][0]]++;

            for (; i < v.size() && v[i][1] < st; i++)
            {
                mp[v[i][0]]--;
                if (!mp[v[i][0]])
                    mp.erase(v[i][0]);
            }

            ans[q[1]] = n - mp.size();
        }
        return ans;
    }
};

// @lc app=leetcode id=2747 lang=cpp