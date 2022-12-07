#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
public:
    vector<TreeNode*> generateTrees(int n, int s = 1)
    {
        if(s > n)
            return {NULL};
        vector<TreeNode *> ans;
        for(int rootVal = s; rootVal <= n; rootVal++)
        {
            auto left_subtrees = generateTrees(rootVal - 1, s);
            auto right_subtrees = generateTrees(n, rootVal + 1);
            for(auto ls: left_subtrees)
                for(auto rs: right_subtrees)
                {
                    auto root = new TreeNode(rootVal);
                    root->left = ls;
                    root->right = rs;
                    ans.push_back(root);
                }
        }
        return ans;
    }
};