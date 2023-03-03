#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    unordered_map<string, vector<TreeNode *>> ump;
    string inorder(TreeNode *root)
    {
        if (!root)
            return "";
        string s = "(" + inorder(root->left) + to_string(root->val) + inorder(root->right) + ")";
        ump[s].push_back(root);
        return s;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        vector<TreeNode *> ans;
        inorder(root);
        for (auto &[s, v] : ump)
            if (v.size() >= 2)
                ans.push_back(v.back());
        return ans;
    }
};



class Solution
{
    unordered_map<string, int> ump;
    vector<TreeNode *> ans;
    string inorder(TreeNode *root)
    {
        if (!root)
            return "";
        string s = "(" + inorder(root->left) + to_string(root->val) + inorder(root->right) + ")";
        if (++ump[s] == 2)
            ans.push_back(root);
        return s;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        inorder(root);
        return ans;
    }
};