#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    string longestPrefix(string s)
    {
        long h1 = 0, h2 = 0, mul = 1, len = 0, mod = 1e9 + 7;
        for (int i = 0, j = s.size() - 1; j > 0; i++, j--)
        {
            int f = s[i] - 'a', l = s[j] - 'a';
            h1 = (h1 * 26 + f) % mod;
            h2 = (h2 + mul * l) % mod;
            mul = (mul * 26) % mod;
            if (h1 == h2)
                len = i + 1;
        }
        return s.substr(0, len);
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    string longestPrefix(string s)
    {
        vector<int> lps(s.size(), 0);
        int j = 0;
        for (int i = 1; i < s.size(); i++)
            if (s[i] == s[j])
                lps[i] = ++j;
            else if (j > 0) 
                j = lps[j - 1], i--;
        return s.substr(0, j);
    }
};


// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    void generateLPS(vector<int> &lps, string p)
    {
        for (int i = 1, j = 0; i < p.size();)
            if (p[i] == p[j])
                lps[i++] = ++j;
            else if (j)
                j = lps[j - 1];
            else i++;
    }

public:
    string longestPrefix(string s)
    {
        string ans = "";
        vector<int> lps(s.size(), 0);
        generateLPS(lps, s);

        if (!lps.back())
            return "";

        int i = lps.size() - 1;
        while (lps[i])
            i--;
        i = lps[i + 1] - 1;

        for (; i < lps.back(); i++)
            ans += s[i];
        return ans;
        // return s.substr(i, lps.back());
    }
};


// MLE

class Solution
{
public:
    string longestPrefix(string s)
    {
        string ans, pf = "", sf = "";
        for (int i = 0, j = s.size() - 1; i < s.size() - 1; i++, j--)
        {
            pf += s[i];
            sf = s[j] + sf;
            if (pf == sf)
                ans = pf;
        }
        return ans;
    }
};


// @lc app=leetcode id=1392 lang=cpp