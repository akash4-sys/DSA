#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    vector<string> ans;
    string path = "";
    void clean()
    {
        path.pop_back();
        while(!path.empty() && path.back() != '>')
            path.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if(!root)
            return {};
        path += to_string(root->val) + "->";
        if (!root->left && !root->right)
            path.resize(path.size() - 2), ans.push_back(path);
        binaryTreePaths(root->left);
        binaryTreePaths(root->right);
        clean();
        return ans;
    }
};


class Solution
{
    vector<string> ans;
public:
    vector<string> binaryTreePaths(TreeNode *root, string path = "", int r = 1)
    {
        if(r) path = to_string(root->val);
        if(!root->left && !root->right)
        {
            ans.push_back(path);
            return ans;
        }
        if(root->left)
            binaryTreePaths(root->left, path + "->" + to_string(root->left->val), 0);
        if(root->right)
            binaryTreePaths(root->right, path + "->" + to_string(root->right->val), 0);
        return ans;
    }
};