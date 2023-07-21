#include "headers.h"

class Solution
{
    bool isBeautiful(int n)
    {
        for (int i = 1; i <= 15625; i *= 5)
            if (n == i)
                return 1;
        return 0;
    }

    int rec(string &s, int n, int i)
    {
        if (i == s.size())
            return isBeautiful(n) ? 1 : 100;

        int res = 100;
        if (isBeautiful(n) && s[i] != '0')
            res = min(res, rec(s, s[i] - '0', i + 1) + 1);
        return min(res, rec(s, (n * 2) + (s[i] - '0'), i + 1));
    }

public:
    int minimumBeautifulSubstrings(string s)
    {
        int ans = rec(s, 0, 0);
        return (s[0] == '0') || ans == 100 ? -1 : ans;
    }
};

class Solution
{
    bool isBeautiful(string &s)
    {
        for (int n = 1, len = 1; len <= 15; n *= 5, len = 32 - __builtin_clz(n))
        {
            int flag = 1;
            if (len != s.size())
                continue;
            for (int i = 0; i < len; i++)
            {
                int x = (n & (1 << i)) ? 1 : 0;
                if (x != s[len - i - 1] - '0')
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                return 1;
        }
        return 0;
    }

    int rec(string &s, string r, int i)
    {
        if (i == s.size())
            return isBeautiful(r) ? 1 : 100;

        int res = 100;
        if (isBeautiful(r) && s[i] != '0')
            res = min(res, rec(s, string(1, s[i]), i + 1) + 1);
        return min(res, rec(s, r + s[i], i + 1));
    }

public:
    int minimumBeautifulSubstrings(string s)
    {
        int ans = rec(s, "", 0);
        return ans == 100 ? -1 : ans;
    }
};

// @lc app=leetcode id=2767 lang=cpp