#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<int> ans;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            int n = q.size(), val;
            while(n--)
            {
                auto r = q.front();
                q.pop();
                val = r->val;
                if(r->left)
                    q.push(r->left);
                if(r->right)
                    q.push(r->right);
            }
            ans.push_back(val);
        }
        return ans;
    }
};