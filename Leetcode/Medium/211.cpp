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

    bool search(TrieNode *root, string s, int i)
    {
        if (i == s.size())
            return root->isEnd;
        for (char c = 0; c <= 25 && s[i] == '.'; c++)
            if (root->child[c] && search(root->child[c], s, i + 1))
                return 1;
        return s[i] != '.' && root->child[s[i] - 'a'] && search(root->child[s[i] - 'a'], s, i + 1);
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

    bool search(string word)
    {
        TrieNode *root = node;
        return search(root, word, 0);
    }
};

class WordDictionary
{
    Trie trie;
public:
    WordDictionary(){}

    void addWord(string word)
    {
        trie.insert(word);
    }

    bool search(string word)
    {
        return trie.search(word);
    }
};