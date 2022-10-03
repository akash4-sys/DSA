#include "../../headers.h"


// Similar but hard to read approach
class Solution
{
public:
    int findLUSlength(vector<string> &s)
    {
        unordered_map<string, int> m;
        for (auto &ss : s)
            ++m[ss];
        sort(begin(s), end(s), [](const auto &a, const auto &b)
             { return a.size() > b.size(); });
        for (int i = 0; i < s.size(); ++i)
        {
            if (m[s[i]] == 1)
            {
                bool unique = true;
                for (int j = 0; j < i && s[i].size() < s[j].size() && unique; ++j)
                {
                    int p = 0;
                    for (int k = 0; k < s[j].size() && p < s[i].size(); ++k)
                        p += s[i][p] == s[j][k];
                    if (p == s[i].size())
                        unique = false;
                }
                if (unique)
                    return s[i].size();
            }
        }
        return -1;
    }
};




class Solution
{
    bool LCS(string a, string b, int i = 0)
    {
        if (b.size() < a.size())
            return 0;
        for (auto c : b)
            if (i < a.size() && a[i] == c)
                i++;
        return i == a.size();
    }

public:
    int findLUSlength(vector<string> &v)
    {
        int ans = -1;
        for (int i = 0; i < v.size(); i++)
        {
            int j = 0;
            for (; j < v.size(); j++)
            {
                if (i == j)
                    continue;
                if (LCS(v[i], v[j]))
                    break;
            }
            if (j == v.size())
                ans = max(ans, (int)v[i].size());
        }
        return ans;
    }
};