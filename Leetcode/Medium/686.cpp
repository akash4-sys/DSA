#include "../../headers.h"

// Time complexity - O(N)
// Space Complexity - O(N)
// Using KMP algorithm

class Solution
{
    vector<int> lps;
    void generateLPS(string &p)
    {
        for (int i = 1, j = 0; i < p.size();)
            if (p[i] == p[j] || !j)
            {
                j = p[i] == p[j] ? j + 1 : 0;
                lps[++i] = j;
            }
            else j = lps[j];
    }

public:
    int repeatedStringMatch(string s, string p)
    {
        lps = vector<int>(p.size() + 1, 0);     // one based lps
        generateLPS(p);
        for (int i = 0, j = 0; i < s.size();)
        {
            for (; j < p.size() && s[(i + j) % s.size()] == p[j]; j++);
            if (j == p.size())
                return (i + j - 1) / s.size() + 1;
            j = lps[j];
            i += max(1, j - lps[j]);
        }
        return -1;
    }
};


// Time complexity - O(N)
// Space Complexity - O(N^2)
// Using KMP algorithm

class Solution
{
    vector<int> lps;
    void generateLPS(string &p)
    {
        for (int i = 1, j = 0; i < p.size();)
            if (p[i] == p[j])
                lps[i++] = ++j;
            else if (j)
                j = lps[j - 1];
            else
                i++;
    }

    bool found(string &s, string &p)
    {
        for (int i = 0, j = 0; i < s.size();)
        {
            if (s[i] == p[j])
                i++, j++;
            if (j == p.size())
                return 1;
            if (i < s.size() && s[i] != p[j])
                j ? j = lps[j - 1] : i++;
        }
        return 0;
    }

public:
    int repeatedStringMatch(string s, string p)
    {
        string t = s;
        int ans = 1, k = 2;
        while (s.size() < p.size())
            ans++, s += t;

        lps = vector<int>(p.size(), 0);
        generateLPS(p);
        while (k && !found(s, p))
            ans++, s += t, k--;
        return k ? ans : -1;
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(1)

class Solution
{
public:
    int repeatedStringMatch(string s, string p)
    {
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            for (j = 0; j < p.size() && s[(i + j) % s.size()] == p[j]; j++);
            if (j == p.size())
                return (i + j - 1) / s.size() + 1;
        }
        return -1;
    }
};

// Time complexity - O(N)
// Space Complexity - O(N^2)

class Solution
{
public:
    int repeatedStringMatch(string s, string p)
    {
        string t = s;
        int ans = 1, k = 2;
        while (s.size() < p.size())
            ans++, s += t;
        while (k && s.find(p) == string::npos)
            ans++, s += t, k--;
        return k ? ans : -1;
    }
};

// @lc app=leetcode id=686 lang=cpp