#include "../../headers.h"

class Solution 
{
    vector<string> ans;
    void recurse(string s, int i)
    {
        if(i == s.size())
        {
            ans.push_back(s);
            return;
        }
        recurse(s, i + 1);
        if(isalpha(s[i]))
            s[i] ^= 32, recurse(s, i + 1);
    }

public:
    vector<string> letterCasePermutation(string s) 
    {
        recurse(s, 0);
        return ans;
    }
};

// @lc app=leetcode id=784 lang=cpp