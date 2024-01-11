#include "../../headers.h"
#include "../../treestructure.h"

// Time Complexity - O(H)
// Space Complexity - O(H)

class Solution
{
    int dfs(stack<TreeNode *> &st) {
        while (1) {
            TreeNode *root = st.top();
            st.pop();
            if (root->left)
                st.push(root->left);
            if (root->right)
                st.push(root->right);
            if (!root->right && !root->left)
                return root->val;
        }
    }

public:
    bool leafSimilar(TreeNode *p, TreeNode *q) {
        stack<TreeNode *> s1{{p}}, s2{{q}};
        while (!s1.empty() && !s2.empty())
            if (dfs(s1) != dfs(s2))
                return 0;
        return s1.empty() && s2.empty();
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    string leafs(TreeNode *root) {
        if(!root)
            return "";
        if(!root->left && !root->right)
            return to_string(root->val) + "-";
        return leafs(root->left) + leafs(root->right);
    }

public:
    bool leafSimilar(TreeNode *p, TreeNode *q) {
        return leafs(p) == leafs(q);
    }
};


// @lc app=leetcode id=872 lang=cpp