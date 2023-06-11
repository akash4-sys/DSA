#include "headers.h"

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
    Trie() : node(new TrieNode()) {}

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

    bool search(string &s)
    {
        TrieNode *root = node;
        return find(s, root, 0, 1);
    }

    bool find(string &s, TrieNode *root, int i, int neq)
    {
        if (i == s.size())
            return root->isEnd && !neq;

        int res = 0;
        for (int c = 0; c < 26 && neq; c++)
            if (root->child[c] && char(c + 'a') != s[i])
                res |= find(s, root->child[c], i + 1, 0);
        
        if (!root->child[s[i] - 'a'])
            return res;
        return res | find(s, root->child[s[i] - 'a'], i + 1, neq);
    }
};

class MagicDictionary
{
    Trie trie;

public:
    MagicDictionary() {}

    void buildDict(vector<string> v)
    {
        for (auto s : v)
            trie.insert(s);
    }

    bool search(string s)
    {
        return trie.search(s);
    }
};