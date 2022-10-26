#include "../../headers.h"

// Decimal to hexadecimal conversion
class Solution
{
    char mp[17] = "0123456789abcdef";
public:
    string toHex(int num)
    {
        unsigned int n = num;
        string ans = n ? "" : "0";
        for(; n ; n /= 16)
            ans = mp[n % 16] + ans;
        return ans;
    }
};

// @lc app=leetcode id=405 lang=cpp