#include "../../headers.h"

class Solution
{
    vector<vector<string>> ans;
    bool isPalindrome(string &s, int i, int j)
    {
        while (i <= j)
            if (s[i++] != s[j--])
                return 0;
        return 1;
    }

    void dfs(string &s, vector<string> v, int i)
    {
        if (i == s.size())
        {
            ans.push_back(v);
            return;
        }

        for (int j = i; j < s.size(); j++)
            if (isPalindrome(s, i, j))
            {
                v.push_back(s.substr(i, j - i + 1));
                dfs(s, v, j + 1);
                v.pop_back();
            }
    }

public:
    vector<vector<string>> partition(string s)
    {
        dfs(s, {}, 0);
        return ans;
    }
};