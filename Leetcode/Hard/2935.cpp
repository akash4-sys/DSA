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

    bool remove(TrieNode *root, int x, int depth = 31)
    {
        if (!root)
            return 0;

        if (depth == -1) {
            root->isEnd = 0;
            return !(root->bit[0] || root->bit[1]);
        }

        int mask = (x >> depth) & 1;
        bool isRemoved = remove(root->bit[mask], x, depth - 1);
        if (isRemoved) {
            delete root->bit[mask];
            root->bit[mask] = nullptr;
        }
        return isRemoved && !(root->bit[0] || root->bit[1]) && !root->isEnd;
    }

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
            if (!root)
                return -1;
            if (!root->bit[mask])
                mask = !mask;
            root = root->bit[mask];
            res |= (mask << i);
        }
        return res;
    }

    void remove(int x) {
        remove(node, x);
    }
};

class Solution
{
public:
    int maximumStrongPairXor(vector<int> &v)
    {
        Trie trie;
        sort(v.begin(), v.end());
        int ans = 0, i = 0, p = -1;
        for (int a : v)
        {
            if (p != -1)
                trie.remove(p);
            while (i < v.size() && v[i] - a <= a)
                trie.insert(v[i++]);
            int b = trie.find(a ^ INT_MAX);
            if (b != -1)
                ans = max(ans, a ^ b);
            p = a;
        }
        return ans;
    }
};