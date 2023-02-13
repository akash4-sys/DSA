#include "headers.h"

class Solution
{
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>> &qrs)
    {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;
        for (int i = 0; i < s.size(); i++)
        {
            long long x = 0;
            for (int j = 0; j < 32 && i + j < s.size(); j++)
            {
                x = (x << 1) + (s[i + j] == '1');
                if (!mp.count(x))
                    mp[x] = {i, i + j};
                if (s[i] == '0')
                    break;
            }
        }

        for (auto &q : qrs)
            if (mp.find(q[0] ^ q[1]) != mp.end())
                ans.push_back(mp[q[0] ^ q[1]]);
            else
                ans.push_back({-1, -1});
        return ans;
    }
};