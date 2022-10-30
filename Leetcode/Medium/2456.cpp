#include "headers.h"

class Solution
{
public:
    vector<vector<string>> mostPopularCreator(vector<string> &c, vector<string> &ids, vector<int> &v)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<pair<long, string>>> mp;
        unordered_map<string, long> p;
        long h = INT_MIN;
        vector<string> crs;
        for (int i = 0; i < v.size(); i++)
        {
            mp[c[i]].push_back({-v[i], ids[i]});
            p[c[i]] += v[i];
            if (h == p[c[i]])
                crs.push_back(c[i]);
            if (h < p[c[i]])
                h = p[c[i]], crs = {c[i]};
        }

        for(string s: crs)
            ans.push_back({s, min_element(mp[s].begin(), mp[s].end())->second});
        return ans;
    }
};



class Solution
{
public:
    vector<vector<string>> mostPopularCreator(vector<string> &c, vector<string> &ids, vector<int> &v)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<pair<long, string>>> mp;
        unordered_map<string, long> p;
        long h = INT_MIN;
        for (int i = 0; i < v.size(); i++)
        {
            mp[c[i]].push_back({-v[i], ids[i]});
            p[c[i]] += v[i];
            h = max(h, p[c[i]]);
        }

        for (auto [cr, vp] : mp)
            if (p[cr] == h)
                ans.push_back({cr, min_element(vp.begin(), vp.end())->second});
        return ans;
    }
};