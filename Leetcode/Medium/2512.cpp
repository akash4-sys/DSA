#include "headers.h"

class Solution
{
public:
    vector<int> topStudents(vector<string> &a, vector<string> &b, vector<string> &rp, vector<int> &id, int k)
    {
        vector<int> ans;
        vector<vector<int>> res;
        unordered_map<string, int> pf, nf;
        for (const string &s : a)
            pf[s] = 1;
        for (const string &s : b)
            nf[s] = 1;

        for (int i = 0; i < id.size(); i++)
        {
            stringstream ss(rp[i]);
            string s;
            int points = 0;
            while (ss >> s)
            {
                points += pf.count(s) ? 3 : 0;
                points += nf.count(s) ? -1 : 0;
            }
            res.push_back({points, id[i]});
        }

        sort(res.begin(), res.end(), [&](const auto &a, const auto &b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });

        for (int i = 0; i <= k; i++)
            ans.push_back(res[i][1]);
        return ans;
    }
};