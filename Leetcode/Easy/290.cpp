#include "../../headers.h"

class Solution
{
public:
    bool wordPattern(string r, string str)
    {
        unordered_map<char, string> mp;
        unordered_map<string, char> rmp;
        istringstream ss(str);
        string s;
        int i = 0;

        while (ss >> s)
        {
            if (i >= r.size() || (mp.count(r[i]) && mp[r[i]] != s))
                return 0;
            if (rmp.count(s) && rmp[s] != r[i])
                return 0;
            mp[r[i]] = s;
            rmp[s] = r[i++];
        }
        return i == r.size();
    }
};


// @lc app=leetcode id=290 lang=cpp