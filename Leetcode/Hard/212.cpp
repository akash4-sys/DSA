#include "../../headers.h"

class Trie
{
public:
    Trie *child[26] = {};
    string *word;

    void push_back(string &s)
    {
        Trie *t = this;
        for (char c : s)
        {
            if (!t->child[c - 'a'])
                t->child[c - 'a'] = new Trie();
            t = t->child[c - 'a'];
        }
        t->word = &s;
    }
};

class Solution
{
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<string> ans;

    void dfs(vector<vector<char>> &grid, Trie *t, int i, int j)
    {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == '.' || !t->child[grid[i][j] - 'a'])
            return;

        char c = grid[i][j];
        t = t->child[c - 'a'];
        if (t->word)
            ans.push_back(*t->word), t->word = nullptr;

        grid[i][j] = '.';
        for (auto &[x, y] : dirs)
            dfs(grid, t, i + x, j + y);
        grid[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>> &grid, vector<string> &words)
    {
        Trie t;
        for (string &w : words)
            t.push_back(w);

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                dfs(grid, &t, i, j);
        return ans;
    }
};



// TLE
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

    void insert(string &word)
    {
        TrieNode *t = node;
        for (auto c : word)
        {
            if (!t->child[c - 'a'])
                t->child[c - 'a'] = new TrieNode();
            t = t->child[c - 'a'];
        }
        t->isEnd = 1;
    }

    bool searchWord(string &word)
    {
        TrieNode *t = node;
        for (auto c : word)
            if (t->child[c - 'a'])
                t = t->child[c - 'a'];
            else return 0;
        return t->isEnd;
    }

    bool prefix(string &word)
    {
        TrieNode *t = node;
        for (auto c : word)
            if (t->child[c - 'a'])
                t = t->child[c - 'a'];
            else return 0;
        return 1;
    }
};

class Solution
{
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    set<string> st;

    void dfs(vector<vector<char>> &grid, Trie *t, string s, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '.')
            return;

        s += grid[i][j];
        if(!t->prefix(s))
            return;
        if(t->searchWord(s))
            st.insert(s);

        char c = grid[i][j];
        grid[i][j] = '.';
        for (auto &[x, y] : dirs)
            dfs(grid, t, s, x + i, y + j);
        grid[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>> &grid, vector<string> &words)
    {
        Trie t;
        for (string w : words)
            t.insert(w);

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                dfs(grid, &t, "", i, j);
        
        return vector<string>(st.begin(), st.end());
    }
};

// @lc app=leetcode id=212 lang=cpp