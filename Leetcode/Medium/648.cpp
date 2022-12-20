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

    bool search(string word)
    {
        TrieNode *root = node;
        for (auto c : word)
            if (root->child[c - 'a'])
                root = root->child[c - 'a'];
            else
                return false;
        return root->isEnd;
    }
};


class Solution
{
public:
    string replaceWords(vector<string> &dict, string s)
    {
        Trie trie;
        for (auto w : dict)
            trie.insert(w);
        
        string ans = "", q = "";
        int f = 0;
        for (auto c : s)
        {
            if(c == ' ')
            {
                if(!f) ans += q + " ";
                f = 0;
                q = "";
                continue;
            }
            q += c;
            if (!f && trie.search(q))
                ans += q + " ", f = 1;
        }
        if (!f) ans += q + " ";
        ans.pop_back();
        return ans;
    }
};


// @lc app=leetcode id=648 lang=cpp