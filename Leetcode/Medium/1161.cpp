#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
public:
    int maxLevelSum(TreeNode *r)
    {
        int ans = 0, lvl = 1, maxSum = INT_MIN;
        for (queue<TreeNode *> q{{r}}; !q.empty(); lvl++)
        {
            int sum = 0;
            for (int k = q.size(); k; k--)
            {
                auto root = q.front();
                sum += root->val;
                q.pop();
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            if (sum > maxSum)
                ans = lvl, sum = maxSum;
        }
        return ans;
    }
};