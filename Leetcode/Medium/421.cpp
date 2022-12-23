#include "../../headers.h"

class TrieNode
{
public:
    TrieNode *bit[2];
    bool isEnd;
};

class Trie
{
    TrieNode *node;

public:
    Trie() : node(new TrieNode()) {}

    void insert(int x)
    {
        TrieNode *root = node;
        for (int i = 31; i >= 0; i--)
        {
            int mask = (x >> i) & 1;
            if (!root->bit[mask])
                root->bit[mask] = new TrieNode();
            root = root->bit[mask];
        }
        root->isEnd = 1;
    }

    int find(int x)
    {
        TrieNode *root = node;
        int res = 0;
        for (int i = 31; i >= 0; i--)
        {
            int mask = (x >> i) & 1;
            if (!root->bit[mask])
                mask = !mask;
            root = root->bit[mask];
            res |= (mask << i);
        }
        return res;
    }
};


class Solution 
{
public:
    int findMaximumXOR(vector<int>& v)
    {
        Trie trie;
        for (int n : v)
            trie.insert(n);
        
        int ans = 0;
        for (int a : v)
        {
            int b = trie.find(a ^ INT_MAX);
            ans = max(ans, a ^ b);
        }
        return ans;
    }
};