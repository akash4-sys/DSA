#include "../../headers.h"

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        int lastIdx[26] = {0}, inStr[26] = {0};
        for (int i = 0; i < s.size(); i++)
            lastIdx[s[i] - 'a'] = i;

        string r = "";
        for (int i = 0; i < s.size(); i++)
            if (!inStr[s[i] - 'a'])
            {
                while (!r.empty() && r.back() > s[i] && i < lastIdx[r.back() - 'a'])
                    inStr[r.back() - 'a'] = 0, r.pop_back();
                r += s[i];
                inStr[s[i] - 'a'] = 1;
            }
        return r;
    }
};

// @lc app=leetcode id=316 lang=cpp