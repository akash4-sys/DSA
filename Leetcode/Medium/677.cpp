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

    void findall(TrieNode *root, vector<string> &res, string &s)
    {
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

class MapSum
{
    unordered_map<string, int> mp;
    Trie trie;
public:
    MapSum(){}

    void insert(string key, int val)
    {
        mp[key] = val;
        trie.insert(key);
    }

    int sum(string s)
    {
        auto vs = trie.startsWith(s);
        int ans = 0;
        for (string &r : vs)
            ans += mp[r];
        return ans;
    }
};