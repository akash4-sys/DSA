#include "../../headers.h"

class Solution
{
public:
    long long distinctNames(vector<string> &v)
    {
        unordered_set<string> st[26];
        for (auto &s : v)
            st[s[0] - 'a'].insert(s.substr(1));

        long long ans = 0;
        for (int i = 0; i < 26; i++)
            for (int j = i + 1; j < 26; j++)
            {
                long long a = 0LL, b = 0LL;
                for (auto &s : st[i])
                    a += (!st[j].count(s));
                for (auto &s : st[j])
                    b += (!st[i].count(s));
                ans += (a * b);
            }
        return ans * 2;
    }
};

// @lc app=leetcode id=2306 lang=cpp