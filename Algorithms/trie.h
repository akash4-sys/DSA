#pragma once

#include <iostream>
#include <vector>

using namespace std;

class TrieNode
{
public:
    TrieNode *child[26];
    bool isEnd;
};

class Trie
{
    TrieNode *node;

    void findall(TrieNode *root, vector<string> &res, string &s)            // DFS from root to find all strings
    {
        if(res.size() >= 3)
            return;
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

    bool search(string word)
    {
        TrieNode *root = node;
        for(auto c: word)
            if(root->child[c - 'a'])
                root = root->child[c - 'a'];
            else return false;
        return root->isEnd;
    }

    bool startsWith(string word)
    {
        TrieNode *root = node;
        for(auto c : word)
            if(root->child[c - 'a'])
                root = root->child[c - 'a'];
            else return false;
        return true;
    }
};