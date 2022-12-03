#include "../../headers.h"

class Solution
{
public:
    string frequencySort(string s)
    {
        vector<pair<int, char>> ch(75, {0, '*'});
        for (char &c : s)
            ch[c - '0'] = {++ch[c - '0'].first, c};
        
        s = "";
        sort(ch.begin(), ch.end(), greater<pair<int, char>>());
        for (auto &[cnt, c] : ch)
            while(cnt--)
                s += c;
        return s;
    }
};


// @lc app=leetcode id=451 lang=cpp