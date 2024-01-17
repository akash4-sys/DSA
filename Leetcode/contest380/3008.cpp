#include "../../headers.h"

class KMP
{
    void generateLPS(string &p, vector<int> &lps)
    {
        for (int i = 1, j = 0; i < p.size();)
            if (p[i] == p[j])
                lps[i++] = ++j;
            else if (j)
                j = lps[j - 1];
            else i++;
    }

public:
    vector<int> strAt(string &s, string &p)
    {
        vector<int> lps(p.size(), 0), res;
        generateLPS(p, lps);

        for (int i = 0, j = 0; i < s.size();)
        {
            if (s[i] == p[j])
                i++, j++;
            if (j == p.size())
                res.push_back(i - j);
            if (i < s.size() && s[i] != p[j])
                j ? j = lps[j - 1] : i++;
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        KMP kmp;
        vector<int> aocc = kmp.strAt(s, a);
        vector<int> bocc = kmp.strAt(s, b);

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