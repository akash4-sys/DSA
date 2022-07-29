#include "../../headers.h"

class Solution
{
public:
    vector<string> ans;

    void finder(string s, string p)
    {
        unordered_map<char, char> mp;
        unordered_set<char> pset;
        for (int i = 0; i < s.length(); i++)
        {
            if (mp.find(s[i]) == mp.end())
            {
                if (pset.find(p[i]) != pset.end())
                    return;

                mp[s[i]] = p[i];
                pset.insert(p[i]);
            }
            else if (mp[s[i]] != p[i])
                return;
        }
        ans.push_back(s);
    }

    vector<string> findAndReplacePattern(vector<string> &words, string p)
    {
        for (string s : words)
            finder(s, p);
        return ans;
    }
};