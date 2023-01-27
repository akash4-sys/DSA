#include "../../headers.h"

class Solution
{
    int dfs(unordered_map<string, int> &mp, string &s, int i, int p)
    {
        if (i == s.size())
            return p >= 2;
        for (int j = i; j < s.size(); j++)
            if (mp.count(s.substr(i, j - i + 1)) && dfs(mp, s, j + 1, p + 1))
                return 1;
        return 0;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& v)
    {
        vector<string> ans;
        unordered_map<string, int> mp;
        for (auto &w : v)
            mp[w]++;
        
        for (auto &w : v)
            if(dfs(mp, w, 0, 0))
                ans.push_back(w);
        return ans;
    }
};


// Trie

class TrieNode
{
public:
    TrieNode *child[26];
    bool isEnd;
};

class Trie
{
    TrieNode *node;
public:
    Trie(): node(new TrieNode()) {}

    void insert(string word)
    {
        TrieNode *root = node;
        for (auto c : word)
        {
            if (!root->child[c - 'a'])
                root->child[c - 'a'] = new TrieNode();
            root = root->child[c - 'a'];
        }
        root->isEnd = 1;
    }

    bool search(string word)
    {
        TrieNode *root = node;
        for(auto c: word)
            if(root->child[c - 'a'])
                root = root->child[c - 'a'];
            else return false;
        return root->isEnd;
    }
};

class Solution
{
    int dfs(Trie &t, string &s, int i, int p)
    {
        if (i == s.size())
            return p >= 2;
        for (int j = i; j < s.size(); j++)
            if (t.search(s.substr(i, j - i + 1)) && dfs(t, s, j + 1, p + 1))
                return 1;
        return 0;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& v)
    {
        vector<string> ans;
        Trie t;
        for (auto &w : v)
            t.insert(w);
        
        for (auto &w : v)
            if(dfs(t, w, 0, 0))
                ans.push_back(w);
        return ans;
    }
};


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