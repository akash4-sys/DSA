#include "../../headers.h"

// Classic Trie
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
    Trie()
    {
        node = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *temp = node;
        for (auto c : word)
        {
            if (!temp->child[c - 'a'])
                temp->child[c - 'a'] = new TrieNode();
            temp = temp->child[c - 'a'];
        }
        temp->isEnd = 1;
    }

    bool search(string word)
    {
        TrieNode *temp = node;
        for(auto c: word)
            if(temp->child[c - 'a'])
                temp = temp->child[c - 'a'];
            else return false;
        return temp->isEnd;
    }

    bool startsWith(string word)
    {
        TrieNode *temp = node;
        for(auto c : word)
            if(temp->child[c - 'a'])
                temp = temp->child[c - 'a'];
            else return false;
        return true;
    }
};