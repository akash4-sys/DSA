#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    vector<int> v;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root);
        return v[k - 1];
    }
};

class Solution
{
    int i = 0, k, ans;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        i++;
        if (i == k)
        {
            ans = root->val;
            return;
        }
        inorder(root->right);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        this->k = k;
        inorder(root);
        return ans;
    }
};

class Solution
{
public:
    int kthSmallest(TreeNode *root, int &k)
    {
        if (root)
        {
            int x = kthSmallest(root->left, k);
            return !k ? x : !--k ? root->val : kthSmallest(root->right, k);
        }
    }
};