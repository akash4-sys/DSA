#include "headers.h"
#include "treestructure.h"

class Solution
{
    vector<int> v;
    void levelOrder(TreeNode *root, int lvl)
    {
        if (!root)
            return;
        if (lvl >= v.size())
            v.push_back(0);
        v[lvl] += root->val;
        levelOrder(root->left, lvl + 1);
        levelOrder(root->right, lvl + 1);
    }

public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        int lvl = 0;
        levelOrder(root, 0);
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty())
        {
            lvl++;
            for(int k = q.size(); k; k--)
            {
                auto *r = q.front();
                q.pop();
                int sum = r->left ? r->left->val : 0;
                sum += r->right ? r->right->val : 0;

                if(r->left)
                {
                    r->left->val = v[lvl] - sum;
                    q.push(r->left);
                }
                if(r->right)
                {
                    r->right->val = v[lvl] - sum;
                    q.push(r->right);
                }
            }
        }      
        root->val = 0;
        return root;
    }
};