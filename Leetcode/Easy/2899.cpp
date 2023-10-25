#include "../../headers.h"

class Solution
{
public:
    vector<int> lastVisitedIntegers(vector<string> &words)
    {
        vector<int> ans, v;
        int cnt = 0;
        for (auto &s : words)
            if (s == "prev")
                ans.push_back(++cnt > v.size() ? -1 : v[v.size() - cnt]);
            else
                v.push_back(stoi(s)), cnt = 0;
        return ans;
    }
};