#include "../../headers.h"

class Solution
{
    unordered_set<string> ump;
    vector<string> ans, dict;
    void dfs(string s, int i)
    {
        if(i == s.size())
        {
            string sentence;
            for(string w: dict)
                sentence += (sentence.size() ? " " : "") + w;
            ans.push_back(sentence);
        }
        for(int j = i + 1; j <= s.size(); j++)
        {
            string r = s.substr(i, j - i);
            if(!ump.count(r))
                continue;
            dict.push_back(r);
            dfs(s, j);
            dict.pop_back();
        }
        return;
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        ump = unordered_set<string>(begin(wordDict), end(wordDict));
        dfs(s, 0);
        return ans;
    }
};