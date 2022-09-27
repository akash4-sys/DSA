#include "../../headers.h"

class Solution
{
public:
    string pushDominoes(string s)
    {
        int n = s.length(), force = 0;
        string ans;
        vector<int> dom(s.length(), 0);
        for (int i = n - 1; i >= 0; i--)
        {
            if(s[i] == 'L')
                force = n, dom[i] = -n;
            if(s[i] == '.' && force)
                dom[i] = -(--force);
            if(s[i] == 'R')
                force = 0;
        }

        force = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'R')
                force = n;
            if(s[i] == '.' && force)
                --force;
            if(s[i] == 'L')
                force = 0;
            int x = dom[i] + force;
            ans += x > 0 ? 'R' : (x < 0 ? 'L' : '.');
        }
        return ans;
    }
};

// @lc app=leetcode id=838 lang=cpp