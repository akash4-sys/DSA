#include "../../headers.h"

class Solution
{
public:
    vector<string> phone = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    void recurse(string digits, string s, int x)
    {
        if(digits.length() == x)
        {
            ans.push_back(s);
            return;
        }
        for(auto c: phone[digits[x] - '2'])
        {
            s.push_back(c);
            recurse(digits, s, x+1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if(digits.length() == 0)
            return ans;
        string s;
        recurse(digits, s, 0);
    }
};