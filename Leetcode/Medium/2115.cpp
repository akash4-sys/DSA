#include "../../headers.h"

class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &r, vector<vector<string>> &ing, vector<string> &supp)
    {
        vector<string> ans;
        unordered_map<string, int> uspp;
        int n = 0;
        for(string s: r)
            uspp[s] = n++;
        for(string s: supp)
            uspp[s] = n++;
        
        n = r.size() + supp.size();
        vector<vector<int>> g(n + 1);
        vector<int> indegree(n, 0);
        for(int i = 0; i < n - supp.size(); i++)
            for(auto s: ing[i])
                g[uspp.count(s) ? uspp[s] : n].push_back(i), indegree[i]++;

        queue<int> q;
        for(int i = 0; i < n; i++)
            if(!indegree[i])
                q.push(i);

        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            if(v < r.size())
                ans.push_back(r[v]);
            for(auto &c: g[v])
                if(c != n && --indegree[c] == 0)
                    q.push(c);
        }
        return ans;
    }
};



// A bit optimised
class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &r, vector<vector<string>> &ing, vector<string> &supp)
    {
        vector<string> ans;
        unordered_map<string, int> uspp;
        int n = 0;
        for(string s: r)
            uspp[s] = n++;
        for(string s: supp)
            uspp[s] = n++;
        
        n = r.size() + supp.size();
        vector<vector<int>> g(n + 1);
        vector<int> indegree(n, 0);
        queue<int> q;

        for(int i = 0; i < n; i++)
        {
            if(i < r.size())
                for(auto s: ing[i])
                    g[uspp.count(s) ? uspp[s] : n].push_back(i), indegree[i]++;
            if(!indegree[i])
                q.push(i);
        }

        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            if(v < r.size())
                ans.push_back(r[v]);
            for(auto &c: g[v])
                if(c != n && --indegree[c] == 0)
                    q.push(c);
        }
        return ans;
    }
};


// @lc app=leetcode id=2115 lang=cpp