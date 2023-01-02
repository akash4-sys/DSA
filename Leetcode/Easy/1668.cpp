#include "../../headers.h"

class Solution 
{
    void generateLPS(string &p, vector<int> &lps)
    {
        for (int i = 1, j = 0; i < p.size();)
            if (p[i] == p[j])
                lps[i++] = ++j;
            else if(j)
                j = lps[j - 1];
            else i++;
    }

    bool found(string &s, string &p)
    {
        vector<int> lps(p.size(), 0);
        generateLPS(p, lps);

        for (int i = 0, j = 0; i < s.size();)
        {
            if (s[i] == p[j])
                i++,  j++;
            if (j == p.size())
                return 1;
            if (i < s.size() && s[i] != p[j])
                j ? j = lps[j - 1] : i++;
        }
        return 0;
    }

public:
    int maxRepeating(string s, string r)
    {
        int k = 0;
        string t = r;
        while (found(s, t))
            k++, t += r;
        return k;
    }
};