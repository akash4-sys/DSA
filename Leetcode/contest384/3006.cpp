#include "../../headers.h"

class KMP
{
    void generateLPS(vector<int> &p, vector<int> &lps)
    {
        for (int i = 1, j = 0; i < p.size();)
            if (p[i] == p[j])
                lps[i++] = ++j;
            else if (j)
                j = lps[j - 1];
            else i++;
    }

public:
    int count(vector<int> &s, vector<int> &p)
    {
        vector<int> lps(p.size(), 0);
        generateLPS(p, lps);

        int res = 0;
        for (int i = 0, j = 0; i < s.size();)
        {
            if (s[i] == p[j])
                i++, j++;
            if (j == p.size())
                res++;
            if (i < s.size() && s[i] != p[j])
                j ? j = lps[j - 1] : i++;
        }
        return res;
    }
};

class Solution
{
public:
    int countMatchingSubarrays(vector<int> &v, vector<int> &p)
    {
        KMP kmp;
        vector<int> a(v.size() - 1);
        for (int i = 0; i < v.size() - 1; i++)
            a[i] = v[i + 1] > v[i] ? 1 : (v[i + 1] == v[i] ? 0 : -1);
        return kmp.count(a, p);
    }
};