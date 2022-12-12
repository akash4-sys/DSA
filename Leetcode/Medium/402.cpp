#include "../../headers.h"

class Solution
{
public:
    string removeKdigits(string s, int k)
    {
        string ans = "";
        for (char c : s)
        {
            while(ans.size() && ans.back() > c && k)
                ans.pop_back(), k--;
            if(ans.size() || c != '0')
                ans += c;
        }

        while(ans.size() && k--)
            ans.pop_back();
        return ans.empty() ? "0" : ans;
    }
};