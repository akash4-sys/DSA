#include "../../headers.h"

// Time Complexity - O(N^4)
// Space Complexity - O(N^3)

class Solution
{
public:
    bool isScramble(string s, string t)
    {
        int n = s.size();
        vector dp(n + 1 , vector(n, vector<int>(n, 0)));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[1][i][j] = s[i] == t[j];
        
        for (int len = 2; len <= n; len++)
            for (int i = 0; i < n + 1 - len; i++)
                for (int j = 0; j < n + 1 - len; j++)
                    for (int slen = 1; slen < len; slen++)
                    {
                        int prefixOfST = dp[slen][i][j], suffixOfST = dp[len - slen][i + slen][j + slen];
                        int pfS_sfT = dp[slen][i][j + len - slen], sfS_pfT = dp[len - slen][i + slen][j];
                        dp[len][i][j] |= prefixOfST && suffixOfST;
                        dp[len][i][j] |= pfS_sfT && sfS_pfT;
                    }
        return dp[n][0][0];
    }
};

// Time Complexity - O(N^4)
// Space Complexity - O(N^2)

class Solution
{
    unordered_map<string, bool> mp;
    bool check(string &s, string &t, int i)
    {
        string pf = s.substr(0, i), sf = s.substr(i), pt = t.substr(0, i), st = t.substr(i);
        return (isScramble(pf, pt) && isScramble(sf, st)) ||
               (isScramble(pf, t.substr(t.size() - i)) && isScramble(sf, t.substr(0, t.size() - i)));
    }

    bool isAnagram(string &s, string &t)
    {
        int ch[26] = {0}, res = 0;
        for (int i = 0; i < s.size(); i++)
            ch[s[i] - 'a']++, ch[t[i] - 'a']--;
        for (int i = 0; i < 26; i++)
            res |= ch[i];
        return res;
    }

public:
    bool isScramble(string s, string t)
    {
        if (s == t)
            return 1;
        string r = s + t;
        if (mp.count(r))
            return mp[r];
        if (!isAnagram(s, t))
            return mp[r] = 0;
        for (int i = 1; i < s.size(); i++)
            if (check(s, t, i))
                return mp[r] = 1;
        return mp[r] = 0;
    }
};