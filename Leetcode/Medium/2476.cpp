#include "headers.h"
#include "treestructure.h"

class Solution
{
    vector<int> v;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

public:
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &qer)
    {
        inorder(root);
        vector<vector<int>> ans;
        for(int q: qer)
        {
            auto it = lower_bound(v.begin(), v.end(), q);
            if(it != end(v) && *it == q)
                ans.push_back({q, q});
            else
                ans.push_back({it == v.begin() ? -1 : *prev(it), it == v.end() ? -1 : *it});
        }
        return ans;
    }
};