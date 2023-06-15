#include "../../headers.h"
#include "../../treestructure.h"

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        int pval = -1, ans = INT_MAX;
        while (root)
        {
            if (!root->left)
            {
                if (pval != -1)
                    ans = min(ans, root->val - pval);
                pval = root->val;
                root = root->right;
            }
            else
            {
                auto prev = root->left;
                while (prev->right)
                    prev = prev->right;
                prev->right = root;
                auto curr = root;
                root = root->left;
                curr->left = NULL;
            }
        }
        return ans;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    int ans = INT_MAX, x = -1;
public:
    int getMinimumDifference(TreeNode *root)
    {
        if(root->left)
            getMinimumDifference(root->left);
        if(x >= 0)
            ans = min(ans, root->val - x);
        x = root->val;
        if(root->right)
            getMinimumDifference(root->right);
        return ans;
    }
};
