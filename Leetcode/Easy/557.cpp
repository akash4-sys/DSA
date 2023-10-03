#include "../../headers.h"

class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string r, ans = "";
        while (ss >> r)
        {
            reverse(r.begin(), r.end());
            ans += r + " ";
        }
        ans.pop_back();
        return ans;
    }
};