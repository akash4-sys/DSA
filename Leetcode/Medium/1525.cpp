#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(26) - O(1)

class Solution
{
public:
    int numSplits(string s)
    {
        int l[26] = {0}, r[26] = {0}, dl = 0, dr = 0, ans = 0;
        for(char c: s)
            dr += ++r[c - 'a'] == 1;
        for(int i = 0; i < s.size(); i++)
        {
            dl += ++l[s[i] - 'a'] == 1;
            dr -= --r[s[i] - 'a'] == 0;
            ans += dl == dr;
        }
        return ans;
    }
};

// Time Complexity - O(N * 26)
// Space Complexity - O(N)
class Solution
{
    int numOfSetBits(int ch, int res = 0)
    {
        for (int i = 0; i < 26; i++)
            if (ch & (1 << i))
                res++;
        return res;
    }

public:
    int numSplits(string s)
    {
        int ans = 0;
        vector<int> pre(s.size()), suf(s.size());
        for (int i = 0, ch = 0; i < s.size(); i++)
            ch |= (1 << (s[i] - 'a')), pre[i] = numOfSetBits(ch);
        for (int i = s.size() - 1, ch = 0; i >= 0; i--)
            ch |= (1 << (s[i] - 'a')), suf[i] = numOfSetBits(ch);
        for (int i = 1; i < s.size(); i++)
            ans += pre[i - 1] == suf[i];
        return ans;
    }
};

// @lc app=leetcode id=1525 lang=cpp