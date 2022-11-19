#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *p, TreeNode *q)
    {
        if(!p && !q) return NULL;
        
        int x = p ? p->val : 0, y = q ? q->val : 0;
        TreeNode *mergedTree = new TreeNode(x + y);
        mergedTree->left = mergeTrees(p ? p->left : NULL, q ? q->left : NULL);
        mergedTree->right = mergeTrees(p ? p->right : NULL, q ? q->right : NULL);
        return mergedTree;
    }
};


// Merged Tree is using old tree pointers which is not safe incase
// you want to delete something in original trees in real world scenario
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *p, TreeNode *q)
    {
        if(!p || !q) return p ? p : q;
        TreeNode *mergedTree = new TreeNode(p->val + q->val);
        mergedTree->left = mergeTrees(p->left, q->left);
        mergedTree->right = mergeTrees(p->right, q->right);
        return mergedTree;
    }
};