#include "../../headers.h"
#include "../../treestructure.h"

// Binary Lifting
// Time Complexity - O(log(max(K) * N)) + O(logK)
// Space Complexity - O(N*20)

class TreeAncestor
{
    int n;
    vector<vector<int>> dp;

public:
    TreeAncestor(int n, vector<int> &par)
    {
        this->n = n;
        dp = vector<vector<int>>(n, vector<int>(20, -1));

        for (int i = 0; i < n; i++)
            dp[i][0] = par[i];

        for (int i = 0; i < n; i++)
            for (int j = 1; j < 20; j++)
            {
                int x = dp[i][j - 1];
                if(x != -1)
                    dp[i][j] = dp[x][j - 1];
            }
    }

    int getKthAncestor(int node, int k)
    {
        for(int j = 0; j < 20; j++)
            if(k & (1 << j))
            {
                node = dp[node][j];
                if(node == -1)
                    return -1;
            }
        return node;
    }
};


// TLE
class TreeAncestor
{
    int n;
    vector<vector<int>> dp;

public:
    TreeAncestor(int n, vector<int> &par)
    {
        this->n = n;
        dp = vector<vector<int>>(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
            dp[i][0] = par[i];

        for (int i = 0; i < n; i++)
            for (int j = 1; j < n && dp[i][j - 1] != -1; j++)
                dp[i][j] = dp[i][j - 1] != -1 ? par[dp[i][j - 1]] : -1;
    }

    int getKthAncestor(int node, int k)
    {
        return dp[node][k - 1];
    }
};


// TLE
class TreeAncestor
{
    int n;
    vector<int> par;
    vector<vector<int>> dp;
public:
    TreeAncestor(int n, vector<int> &par)
    {
        this->n = n;
        this->par = par;
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -2)); 
    }

    int getKthAncestor(int node, int k)
    {
        if(k == 0 || node == -1)
            return node;
        if(dp[node][k] != -2)
            return dp[node][k];
        return dp[node][k] = getKthAncestor(par[node], k - 1);
    }
};



// Recursive
// TLE
class TreeAncestor
{
    int n;
    vector<int> par;
public:
    TreeAncestor(int n, vector<int> &par)
    {
        this->n = n;
        this->par = par;
    }

    int getKthAncestor(int node, int k)
    {
        if(k == 0)
            return node;
        return getKthAncestor(par[node], k - 1);
    }
};
// @lc app=leetcode id=1483 lang=cpp