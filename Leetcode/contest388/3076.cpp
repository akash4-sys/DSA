#include "../../headers.h"

class Solution
{
public:
    vector<string> shortestSubstrings(vector<string> &v)
    {
        int n = v.size();
        vector<string> ans(n, string(21, 'z'));
        unordered_map<string, int> mp;
        for (auto &s : v)
        {
            unordered_set<string> st;
            for (int i = 0; i < s.size(); i++)
            {
                string r = "";
                for (int j = i; j < s.size(); j++)
                    r += s[j], st.insert(r);
            }
            for (auto &r : st)
                mp[r]++;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < v[k].size(); i++)
            {
                string r = "";
                for (int j = i; j < v[k].size(); j++) {
                    r += v[k][j];
                    if (mp[r] == 1)
                    {
                        if (r.size() < ans[k].size())
                            ans[k] = r;
                        else if (r.size() == ans[k].size())
                            ans[k] = min(ans[k], r);
                    }
                }
            }
            if (ans[k].size() == 21)
                ans[k] = "";
        }
        return ans;
    }
};