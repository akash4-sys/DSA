#include "../../headers.h"

#define ll long long
class Solution
{
    ll mod = 1e9 + 7, ch = 26;
    ll patternHash(string &p)
    {
        ll hash = 0;
        for (ll i = p.size() - 1, pw = 1; i >= 0; i--)
        {
            hash = (hash + ((p[i] - 'a') * pw)) % mod;
            pw *= 26;
        }
        return hash;
    }

public:
    int strStr(string s, string p)
    {
        return patternHash(p);
    }
};



class KMP
{
    void generateLPS(string &p, vector<int> &lps)
    {
        for (int i = 1, j = 0; i < p.size();)
        {
            if (p[i] == p[j])
                lps[i++] = ++j;
            else if (j)
                j = lps[j - 1];
            else
                i++;
        }
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

class Solution
{
public:
    int strStr(string s, string p)
    {
        KMP kmp;
        return kmp.strAt(s, p);
    }
};

class Solution
{
public:
    int strStr(string s, string p)
    {
        auto it = s.find(p);
        return (it == string::npos) ? -1 : it;
    }
};