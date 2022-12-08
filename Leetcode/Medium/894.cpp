#include "../../headers.h"
#include "../../treestructure.h"

// @ generate all possible Full Binary Trees

// @ Without clone solution here all binary tress are techinally linked
// @ so to unlink we have to create deep copy of trees every time

class Solution
{
    unordered_map<int, vector<TreeNode *>> dp = {{1, {new TreeNode(0)}}};
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n % 2 == 0)     // full binary trees must have odd number of nodes
            return {};
        if(dp.count(n))
            return dp[n];
        vector<TreeNode *> ans;
        for (int i = 0; i < n; i++)
        {
            auto left = allPossibleFBT(i), right = allPossibleFBT(n - i - 1);
            for (auto l : left)
                for (auto r : right)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
        }
        return dp[n] = ans;
    }
};


// @ Deep Copy Solution

class Solution
{
    unordered_map<int, vector<TreeNode *>> dp = {{1, {new TreeNode(0)}}};
    TreeNode *deepCopy(TreeNode *root)
    {
        TreeNode *r = new TreeNode(0);
        r->left = root->left ? deepCopy(root->left) : NULL;
        r->right = root->right ? deepCopy(root->right) : NULL;
        return r;
    }

public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n % 2 == 0) 
            return {};
        if(dp.count(n))
            return dp[n];
        vector<TreeNode *> ans;
        for (int i = 0; i < n; i++)
        {
            auto left = allPossibleFBT(i), right = allPossibleFBT(n - i - 1);
            for (auto l : left)
                for (auto r : right)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = deepCopy(l);
                    root->right = deepCopy(r);
                    ans.push_back(root);
                }
        }
        return dp[n] = ans;
    }
};

// @lc app=leetcode id=894 lang=cpp