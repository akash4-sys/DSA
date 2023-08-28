#include "../../headers.h"
#include "../../treestructure.h"

// Binary Lifting
// Time Complexity - O(log(max(K) * N)) + O(logK)
// Space Complexity - O(N*20)

class TreeAncestor
{
    int n, maxDepth;
    vector<vector<int>> ancestor;
public:
    TreeAncestor(int n, vector<int> par)
    {
        this->n = n;
        maxDepth = log2(n) + 1;
        ancestor = vector(n, vector<int>(maxDepth, -1));

        for (int i = 0; i < n; i++)
            ancestor[i][0] = par[i];

        for (int j = 1; j < maxDepth; j++)
            for (int i = 0; i < n; i++)
                if (ancestor[i][j - 1] != -1)
                    ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
    }

    int getKthAncestor(int node, int k)
    {
        for (int i = 0; i < maxDepth; i++)
            if (k & (1 << i))
            {
                node = ancestor[node][i];
                if (node == -1)
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