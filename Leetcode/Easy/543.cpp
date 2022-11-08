#include "../../headers.h"

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
    int recurse(TreeNode *root, int &ans)
    {
        if(!root)
            return 0;
        int l = recurse(root->left, ans), r = recurse(root->right, ans);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode *root, int ans = 0)
    {
        recurse(root, ans);
        return ans;
    }
};