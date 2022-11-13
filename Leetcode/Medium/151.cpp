#include "../../headers.h"

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string r, ans;
        while (ss >> r)
            ans = ' ' + r + ans;
        ans.erase(0, 1);
        return ans;
    }
};


class Solution
{
public:
    string reverseWords(string s)
    {
        string ans = "", r = "";
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (ans.size() || r.size())
                    ans += r + " ";
                r = "";
                while (i > 0 && s[i] == ' ')
                    i--;
            }
            r = s[i] + r;
        }

        ans += r;
        while (ans.back() == ' ')
            ans.pop_back();
        return ans;
    }
};

// @lc app=leetcode id=151 lang=cpp