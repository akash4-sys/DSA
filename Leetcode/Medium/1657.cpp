#include "../../headers.h"

class Solution
{
public:
    bool closeStrings(string s, string r)
    {
        if(s.size() != r.size()) return 0;

        int sch[26] = {0}, rch[26] = {0};
        unordered_map<int, int> mp;
        for(int i = 0; i < r.size(); i++)
            sch[s[i] - 'a']++, rch[r[i] - 'a']++;

        for(int i = 0; i < 26; i++)
            if((sch[i] && !rch[i]) || (!sch[i] && rch[i]))
                return 0;
            else mp[sch[i]]++, mp[rch[i]]--;

        for(auto [_, c]: mp)
            if(c) return 0;
        return 1;
    }
};


// @lc app=leetcode id=1657 lang=cpp