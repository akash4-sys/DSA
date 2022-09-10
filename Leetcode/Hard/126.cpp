#include "../../headers.h"

// perfectly fine preferred solution gives TLE on Leetcode for last TC
class Solution
{
public:
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string beginWord, string endWord, unordered_map<string, unordered_set<string>> adj)
    {
        path.push_back(beginWord);
        if (beginWord == endWord)
        {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for (auto x : adj[beginWord])
            dfs(x, endWord, adj);
        path.pop_back(); // backtrack
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, unordered_set<string>> adj;
        unordered_set<string> uset(begin(wordList), end(wordList));
        unordered_map<string, int> visited; // word -> level
        queue<string> q;

        q.push(beginWord);
        visited[beginWord] = 0;

        while (!q.empty())
        {
            string curr = q.front();
            q.pop();

            for (int i = 0; i < curr.size(); i++)
            {
                string temp = curr;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (temp[i] == c)
                        continue;

                    temp[i] = c;
                    if (uset.count(temp) != 0)
                    {
                        if (visited.count(temp) == 0)
                        {
                            visited[temp] = visited[curr] + 1;
                            adj[curr].insert(temp);
                            q.push(temp);
                        }
                        else if (visited[temp] == visited[curr] + 1)
                            adj[curr].insert(temp);
                    }
                }
            }
        }

        dfs(beginWord, endWord, adj);
        return ans;
    }
};

// optimised to avoid tle only for leetcode
class Solution
{
    vector<vector<string>> ans;
    vector<string> path;
    unordered_map<string, unordered_set<string>> prev;
    void getPaths(const string &w, const string &last)
    {
        path.push_back(w);
        if (w == last)
        {
            reverse(begin(path), end(path));
            ans.push_back(path);
            reverse(begin(path), end(path));
        }
        else
        {
            for (auto &p : prev[w])
            {
                getPaths(p, last);
            }
        }
        path.pop_back();
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &A)
    {
        unordered_set<string> s(begin(A), end(A));
        if (s.count(endWord) == 0)
            return {};
        int N = beginWord.size(), step = 0;
        unordered_map<string, int> m;
        queue<string> q;
        q.push(beginWord);
        m[beginWord] = step;
        while (q.size())
        {
            int cnt = q.size();
            ++step;
            while (cnt--)
            {
                auto u = q.front(), v = u;
                q.pop();
                if (u == endWord)
                {
                    getPaths(endWord, beginWord);
                    return ans;
                }
                for (int i = 0; i < N; ++i)
                {
                    for (char j = 'a'; j <= 'z'; ++j)
                    {
                        if (j == u[i])
                            continue;
                        v[i] = j;
                        if (s.count(v) && (m.count(v) == 0 || m[v] == step) && prev[v].count(u) == 0)
                        {
                            if (m.count(v) == 0)
                            {
                                q.push(v);
                                m[v] = step;
                            }
                            prev[v].insert(u);
                        }
                        v[i] = u[i];
                    }
                }
            }
        }
        cout << 1 << endl;
        return {};
    }
};