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


// Morris Traversal
// Time Complexity - O(N)
// Space Complexity - O(1)
class Solution
{
public:
    int rangeSumBST(TreeNode *root, int l, int h)
    {
        int ans = 0;
        while (root)
        {
            if (!root->left)
            {
                if(root -> val >= l && root -> val <= h) 
                    ans += root -> val;
                root = root->right;
            }
            else
            {
                auto *prev = root->left;
                while (prev->right && prev->right != root)
                    prev = prev->right;
                if(!prev->right)
                    prev->right = root, root = root->left;
                else
                {
                    prev->right = NULL;
                    if(root -> val >= l && root -> val <= h) 
                        ans += root -> val;
                    root = root->right;
                }
            }
        }
        return ans;
    }
};



class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return 0;
        if (root->val < low)
            return rangeSumBST(root->right, low, high);
        if (root->val > high)
            return rangeSumBST(root->left, low, high);
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};