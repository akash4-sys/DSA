#include "../../headers.h"

class Solution
{
public:
    string subStrHash(string s, int p, int m, int k, int hashVal)
    {
        long long curr = 0, j = 0, pk = 1, n = s.size();
        for (int i = n - 1; i >= 0; i--)
        {
            curr = (curr * p + (s[i] - '`')) % m;
            if (i + k >= n)
                (pk *= p) %= m;
            else
                curr = (curr - ((s[i + k] - '`') * pk) % m + m) % m;
            j = curr == hashVal ? i : j;
        }
        return s.substr(j, k);
    }
};

// @lc app=leetcode id=2156 lang=cpp