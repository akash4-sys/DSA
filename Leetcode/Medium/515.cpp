#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        for (queue<TreeNode *> q{{root}}; q.size();)
        {
            int k = q.size(), mx = INT_MIN;
            while (k--)
            {
                auto r = q.front();
                q.pop();
                mx = max(mx, r->val);
                if (r->left)
                    q.push(r->left);
                if (r->right)
                    q.push(r->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};