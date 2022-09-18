#include "headers.h"

class Trie
{
    Trie *ch[26] = {};
    int cnt = 0;
public:
    void insert(string &w, int i = 0)
    {
        auto n = this;
        for(auto c: w)
        {
            if(!n -> ch[c - 'a'])
                n -> ch[c - 'a'] = new Trie();
            n = n -> ch[c - 'a'];
            ++n->cnt;
        }
    }

    int count(string &w, int i = 0)
    {
        return cnt + (i == w.size() ? 0 : ch[w[i] - 'a']->count(w, i + 1));
    }
};

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        Trie t;
        for(auto &w: words)
            t.insert(w);
        vector<int> ans;
        for(auto &w: words)
            ans.push_back(t.count(w));
        return ans;
    }
};






class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        vector<int> ans;
        unordered_map<string, int> ump;
        for(string w: words)
        {
            int x = 0;
            for(int j = w.size(); j >= 1; j--)
            {
                string r = w.substr(0, j);
                if(ump.count(r))
                    x += ump[r];
                else
                    for(string s: words)
                    {
                        int eq = 1;
                        if(r.size() > s.size())
                            continue;
                        for(int k = 0; k < r.length(); k++)
                            if(r[k] != s[k])
                            {
                                eq = 0;
                                break;
                            }
                        if(eq)
                            x += eq, ump[r]++;
                    }
            }
            ans.push_back(x);
        }
        return ans;
    }
};