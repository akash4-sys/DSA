#include "../../headers.h"

class Solution
{
    unordered_set<string> uset;
    bool wordBreak(string s)
    {
        int n = s.size();
        vector<bool> dp(n, false);
        for(int i = 0; i < n - 1; i++)
        {
            if(uset.count(s.substr(0, i+1)))
                dp[i] = true;
            if(!dp[i])
                continue;
            for(int j = i + 1; j < n; j++)
                if(uset.count(s.substr(i+1, j - i)))
                    dp[j] = true;
            if(dp[n - 1])
                return true;
        }
        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> ans;
        uset = unordered_set<string>(begin(words), end(words));
        for(string w: words)
            if(wordBreak(w))
                ans.push_back(w);
        return ans;
    }
};




// TLE
class Solution
{
    unordered_set<string> uset;
    vector<string> ans;
    void dfs(string s, int i)
    {
        if (i == s.size())
            ans.push_back(s);

        for (int j = i + 1; j <= s.size(); j++)
        {
            string r = s.substr(i, j - i);
            if (!uset.count(r))
                continue;
            dfs(s, j);
        }
        return;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            vector<string> wordDict = words;
            uset = unordered_set<string>(begin(wordDict), end(wordDict));
            uset.erase(words[i]);
            dfs(words[i], 0);
        }
        uset = unordered_set<string>(begin(ans), end(ans));
        ans = vector<string>(begin(uset), end(uset));
        return ans;
    }
};