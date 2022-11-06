#include "../../headers.h"

class Solution
{
public:
    string reverseVowels(string s)
    {
        string vowels = "aeiouAEIOU";
        int ch = 0, l = 0, r = s.size() - 1;
        for (char c : vowels)
            ch |= (1 << (c % 32));
            
        while (l < r)
        {
            while (l < r && !(isalpha(s[l]) && (ch & (1 << (s[l] % 32)))))
                l++;
            while (l < r && !(isalpha(s[r]) && (ch & (1 << (s[r] % 32)))))
                r--;
            if(l < r)
                swap(s[l++], s[r--]);
        }
        return s;
    }
};

class Solution
{
public:
    string reverseVowels(string s)
    {
        string vowels = "aeiouAEIOU", r = "";
        int ch = 0;
        for (char c : vowels)
            ch |= (1 << (c % 32));

        for (char c : s)
            if (isalpha(c) && (ch & (1 << (c % 32))))
                r += c;

        for (int i = 0, j = r.size() - 1; i < s.length(); i++)
            if (isalpha(s[i]) && (ch & (1 << (s[i] % 32))))
                s[i] = r[j--];
        return s;
    }
};

// Time Complexity O(N * 10);
// Space Complexity O(1)
class Solution
{
public:
    string reverseVowels(string s)
    {
        string vowels = "aeiouAEIOU", r = "";
        for (char c : s)
            for (char v : vowels)
                if (c == v)
                {
                    r += c;
                    break;
                }
        for (int i = 0, j = r.size() - 1; i < s.length(); i++)
            for (char c : vowels)
                if (s[i] == c)
                {
                    s[i] = r[j--];
                    break;
                }
        return s;
    }
};

// @lc app=leetcode id=345 lang=cpp
