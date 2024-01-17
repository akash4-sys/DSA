#include "../../headers.h"

class Solution
{
    vector<int> occ(string &s, string &a)
    {
        vector<int> idx;
        int i = 0;
        while ((i = s.find(a, i)) != string::npos) {
            idx.push_back(i);
            i += a.size();
        }
        return idx;
    }

public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        vector<int> aocc = occ(s, a);
        vector<int> bocc = occ(s, b);

        vector<int> ans;
        for (int i : aocc)
        {
            int l = lower_bound(bocc.begin(), bocc.end(), i - k) - bocc.begin();
            int r = upper_bound(bocc.begin(), bocc.end(), i + k) - bocc.begin() - 1;
            if (r >= l)
                ans.push_back(i);
        }
        return ans;
    }
};