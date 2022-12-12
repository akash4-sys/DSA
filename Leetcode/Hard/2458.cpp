#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    unordered_map<int, int> level, depth, maxD, maxD2;
    int levelOrder(TreeNode *root, int lvl)
    {
        if(!root)
            return 0;
        level[root->val] = lvl;
        depth[root->val] = max(levelOrder(root->left, lvl + 1), levelOrder(root->right, lvl + 1)) + 1;
        if(maxD[lvl] < depth[root->val])
            maxD2[lvl] = maxD[lvl], maxD[lvl] = depth[root->val];
        else if(maxD2[lvl] < depth[root->val])
            maxD2[lvl] = depth[root->val];
        return depth[root->val];
    }

public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        vector<int> ans;
        levelOrder(root, 0);
        for(auto q : queries)
        {
            int l = level[q];
            int x = l + (maxD[l] == depth[q] ? maxD2[l] : maxD[l]) - 1;
            ans.push_back(x);
        }
        return ans;
    }
};