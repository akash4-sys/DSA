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

// @ Height Balanced Tree

class Solution
{
    int maxDepth(TreeNode *root)
    {
        if(!root) return 0;
        int l = maxDepth(root->left);
        if(l == -1) return -1;
        int r = maxDepth(root->right);
        if(r == -1) return -1;
        if(abs(l - r) > 1) return -1;
        return max(l, r) + 1;
    }
public:
    bool isBalanced(TreeNode *root)
    {
       return maxDepth(root) != -1;
    }
};


// Time Complexity O(NlogN) -- logN is the height of the height balanced tree
// Space Complexity O(N)
class Solution
{
    int maxDepth(TreeNode *root, int lvl = 0)
    {
        return root ? max(maxDepth(root->left, lvl + 1), maxDepth(root->right, lvl + 1)) : lvl;
    }
public:
    bool isBalanced(TreeNode *root)
    {
        if(!root) return 1;
        int l = maxDepth(root->left), r = maxDepth(root->right);
        return abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};