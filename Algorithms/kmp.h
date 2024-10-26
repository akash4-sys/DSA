#pragma once

#include <string>
#include <vector>

using namespace std;

// LPS - Longest Prefix String

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
    int strAt(string &s, string &p)
    {
        vector<int> lps(p.size(), 0);
        generateLPS(p, lps);

        for (int i = 0, j = 0; i < s.size();)
        {
            if (s[i] == p[j])
                i++, j++;
            if (j == p.size())
                return i - j;
            if (i < s.size() && s[i] != p[j])
                j ? j = lps[j - 1] : i++;
        }
        return -1;
    }
};