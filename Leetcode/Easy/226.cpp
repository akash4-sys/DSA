#include "../../headers.h"
#include "../../treestructure.h"

// Iterative
class Solution
{
public:
    TreeNode* invertTree(TreeNode *root)
    {
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            auto r = st.top();
            st.pop();
            if(r)
            {
                st.push(r->left);
                st.push(r->right);
                swap(r->left, r->right);
            }
        }
        return root;
    }
};


class Solution
{
public:
    TreeNode* invertTree(TreeNode *root)
    {
        if(!root)
            return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};