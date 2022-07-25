#include "../../headers.h"

class Solution
{
public:
    vector<string> ans;
    int n;

    void recurse(string s, int open, int close)
    {
        if(open == close && open == n)
        {
            ans.push_back(s);
            return;
        }

        if(open < n)
            recurse(s + "(", open + 1, close);
        if(close < open && close < n)
            recurse(s + ")", open, close + 1);
    }

    vector<string> generateParenthesis(int sz)
    {
        n = sz;
        recurse("", 0, 0);
        return ans;
    }
};