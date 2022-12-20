#include "../../headers.h"

// Time Complexity - O(N^3+logN)
// Space Complexity - O(N)

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string ans;
        for (string w : words)
        {
            if (w.size() == 1 || built.count(w.substr(0, w.size() - 1)))
            {
                ans = w.size() > ans.size() ? w : ans;
                built.insert(w);
            }
        }
        return ans;
    }
};

// Time Complexity - O(N^3+logN) -- logN can be reduced if instead child array unordered_map is used
// Space Comlexity - O(N)

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
    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end());
        string ans = "";
        Trie trie;
        for (auto w : words)
            trie.insert(w);

        for (auto w : words)
        {
            if (w.size() <= ans.size())
                continue;
            string s = "";
            int f = 0;
            for (auto c : w)
            {
                s += c;
                f = trie.search(s);
                if (!f) break;
            }
            if (f) ans = s;
        }
        return ans;
    }
};

// @lc app=leetcode id=720 lang=cpp