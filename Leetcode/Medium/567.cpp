#include "../../headers.h"

class Solution
{
public:
    bool checkInclusion(string p, string s)
    {
        if (p.size() > s.size())
            return 0;
        vector<int> a(26, 0), b(26, 0);
        for (int i = 0; i < p.size(); i++)
            a[p[i] - 'a']++, b[s[i] - 'a']++;
        
        if (a == b)
            return 1;
        for (int i = 1; i <= s.size() - p.size(); i++)
        {
            b[s[i - 1] - 'a']--;
            b[s[i + p.size() - 1] - 'a']++;
            if (a == b)
                return 1;
        }
        return 0;
    }
};



class Solution
{
public:
    bool checkInclusion(string p, string s)
    {
       vector<int> ch(26, 0);
        for (char c : p)
            ch[c - 'a']++;
        
        for (int i = 0; i < s.size(); i++)
            if (ch[s[i] - 'a'])
            {
                int c = 0;
                auto t = ch;
                for (int j = i; j < s.size() && t[s[j] - 'a']; j++)
                    c++, t[s[j] - 'a']--;
                if (c == p.size())
                    return 1;
            }
        return 0;
    }
};


// @lc app=leetcode id=567 lang=cpp