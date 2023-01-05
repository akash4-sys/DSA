#include "../../headers.h"

// Regex

class Solution 
{
public:
    vector<bool> camelMatch(vector<string>& v, string p) 
    {
        vector<bool> ans;
        string r = "[a-z]*";
        for (char &c : p)
            r += string(1, c) + "[a-z]*";
        regex rgx(r);
        for (string &s : v)
            ans.push_back(regex_match(s, rgx));
        return ans;
    }
};

// Time Complexity - O(N ^ 2)
// Space Complexity - O(1)

class Solution
{
    bool isMatch(string &s, string &p)
    {
        int i = 0;
        for (char &c : s)
            if (i < p.size() && c == p[i])
                i++;
            else if (isupper(c))
                return 0;
        return i == p.size();
    }

public:
    vector<bool> camelMatch(vector<string> &v, string p)
    {
        vector<bool> ans;
        for (string &s : v)
            ans.push_back(isMatch(s, p));
        return ans;
    }
};

// @lc app=leetcode id=1023 lang=cpp