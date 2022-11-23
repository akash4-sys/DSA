#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
public:
    vector<int> getAllElements(TreeNode *p, TreeNode *q)
    {
        vector<int> ans;
        stack<TreeNode *> sp, sq;
        while(p || q || !sp.empty() || !sq.empty())
        {
            while(p)
                sp.push(exchange(p, p->left));              // exchange is sp.push(p) and p = p->left;
            while(q)
                sq.push(exchange(q, q->left));
            if(sq.empty() || (!sp.empty() && sp.top()->val <= sq.top()->val))
            {
                p = sp.top();
                sp.pop();
                ans.push_back(p->val);
                p = p->right;
            }
            else
            {
                q = sq.top();
                sq.pop();
                ans.push_back(q->val);
                q = q->right;
            }
        }
        return ans;
    }
};


class Solution
{
    vector<int> ans;
    void inorder(TreeNode *root)
    {
        if(!root)
            return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }

public:
    vector<int> getAllElements(TreeNode *p, TreeNode *q)
    {
        inorder(p);
        inorder(q);
        sort(ans.begin(), ans.end());
        return ans;
    }
};