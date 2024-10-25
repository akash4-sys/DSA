#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int maxPalindromicPrefix(string &r)
    {
        string s = r;
        reverse(s.begin(), s.end());
        s = r + s;

        int n = s.size(), x = 0, y = 0, len = 0;
        vector<int> zArray(n);
        for (int i = 1; i < n; i++)
        {
            zArray[i] = max(0, min(zArray[i - x], y - i + 1));
            while (i + zArray[i] < n && s[zArray[i]] == s[i + zArray[i]])
                x = i, y = i + zArray[i], zArray[i]++;
        }

        for (int i = 0; i < zArray.size(); i++)
            if (zArray[i] == zArray.size() - i && zArray[i] <= r.size())
                len = max(len, zArray[i]);
        return len;
    }

public:
    string shortestPalindrome(string &s)
    {
        if (s.size() == 0)
            return s;
        
        string p = "";
        int len = maxPalindromicPrefix(s);
        while (len < s.size())
            p += s[len++];
        reverse(p.begin(), p.end());
        return p + s;
    }
};