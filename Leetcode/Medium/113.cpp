#include "../../headers.h"
// @lc app=leetcode id=113 lang=cpp

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int tar;
    vector<vector<int>> paths;
    void createPath(TreeNode *root, vector<int> &path, int sum)
    {
        if (!root) return;
        sum += root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == tar)
            paths.push_back(path);
        createPath(root->left, path, sum);
        createPath(root->right, path, sum);
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int t)
    {
        tar = t;
        vector<int> path;
        createPath(root, path, 0);
        return paths;
    }
};


// More concise way

class Solution
{
    vector<vector<int>> paths;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode *root, int t, int sum = 0)
    {
        if(!root) return {};
        sum += root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == t)
            paths.push_back(path);
        pathSum(root->left, t, sum);
        pathSum(root->right, t, sum);
        path.pop_back();
        return paths;
    }
};


