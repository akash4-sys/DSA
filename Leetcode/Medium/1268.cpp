#include "../../headers.h"

class TrieNode
{
public:
    TrieNode *child[26];
    bool isEnd;
};

class Trie
{
    TrieNode *node;

    void findall(TrieNode *root, vector<string> &res, string &s)            // DFS from root to find all strings
    {
        if(res.size() >= 3)
            return;
        if(root->isEnd)
            res.push_back(s);
        for (char c = 'a'; c <= 'z'; c++)
            if (root->child[c - 'a'])
            {
                s += c;
                findall(root->child[c - 'a'], res, s);
                s.pop_back();
            }
    }

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

    vector<string> startsWith(string word)
    {
        TrieNode *root = node;
        for(auto c : word)
            if(root->child[c - 'a'])
                root = root->child[c - 'a'];
            else return {};

        vector<string> res;
        findall(root, res, word);
        return res;
    }
};

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &p, string s)
    {
        vector<vector<string>> ans;
        Trie trie;
        for (auto r : p)
            trie.insert(r);
        
        string q = "";
        for (auto c : s)
            q += c, ans.push_back(trie.startsWith(q));
        return ans;
    }
};