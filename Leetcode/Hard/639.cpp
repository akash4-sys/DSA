#include "../../headers.h"

typedef long long ll;
class Solution
{
    int mod = 1e9 + 7;
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        long long curr = s[0] == '*' ? 9 : 1, last = 1;
        for (int i = 1; i < s.length(); i++)
        {
            ll t = curr;
            if (s[i] == '*')
            {
                curr = 9 * curr % mod;
                if (s[i - 1] == '1')
                    curr = (curr + 9 * last) % mod;
                else if (s[i - 1] == '2')
                    curr = (curr + 6 * last) % mod;
                else if (s[i - 1] == '*')
                    curr = (curr + 15 * last) % mod;
            }
            else
            {
                curr = s[i] != '0' ? curr : 0;
                if (s[i - 1] == '1')
                    curr = (curr + last) % mod;
                else if (s[i - 1] == '2' && s[i] <= '6')
                    curr = (curr + last) % mod;
                else if (s[i - 1] == '*')
                    curr = (curr + (s[i] <= '6' ? 2 : 1) * last) % mod;
            }
            last = t;
        }
        return curr;
    }
};

// @lc app=leetcode id=639 lang=cpp