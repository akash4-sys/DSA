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

public:
    Trie(): node(new TrieNode()) {}

    void insert(string &word)
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

    string prefix(string &word)
    {
        string prefix = "";
        TrieNode *root = node;
        for(auto &c : word)
        {
            if(!root->child[c - 'a'])
                return "";
            root = root->child[c - 'a'];
            prefix += c;
            if (root->isEnd)
                return prefix;
        }
        return "";
    }
};

class Solution
{
public:
    string replaceWords(vector<string> &words, string &sentence)
    {
        Trie trie;
        for (auto &word : words)
            trie.insert(word);
        
        stringstream ss(sentence);
        string word, ans = "";
        while (ss >> word) {
            string res = trie.prefix(word);
            ans += (res.size() ? res : word) + " ";
        }
        ans.pop_back();
        return ans;
    }
};