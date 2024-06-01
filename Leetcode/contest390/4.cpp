#include "../../headers.h"

class TrieNode {
public:
    TrieNode *child[26];
    bool isEnd;
    int idx = -1, len = INT_MAX;
};

class Trie
{
    TrieNode *node;

public:
    Trie(): node(new TrieNode()) {}

    void insert(string &s, int it)
    {
        TrieNode *root = node;
        for (int n = s.size(), i = n - 1; i >= 0; i--)
        {
            if (!root->child[s[i] - 'a'])
                root->child[s[i] - 'a'] = new TrieNode();
            root = root->child[s[i] - 'a'];

            if (root->len > n)
                root->len = n, root->idx = it;
            else if (root->len == n)
                root->idx = min(root->idx, it);
        }
        root->isEnd = 1;
    }

    int longestSuffix(string &s)
    {
        int idx = -1, n = s.size();
        TrieNode *root = node;
        for (int i = n - 1; i >= 0 && root->child[s[i] - 'a']; i--)
            root = root->child[s[i] - 'a'], idx = root->idx;
        return idx;
    }
};

class Solution
{
public:
    vector<int> stringIndices(vector<string> &words, vector<string> &query)
    {
        int len = INT_MAX, idx = -1;
        vector<int> ans;
        Trie trie;
        for (int i = 0; i < words.size(); i++) {
            trie.insert(words[i], i);
            if (len > words[i].size())
                len = words[i].size(), idx = i;
        }
        
        for (auto &s : query) {
            int i = trie.longestSuffix(s);
            ans.push_back(i == -1 ? idx : i);
        }
        return ans;
    }
};