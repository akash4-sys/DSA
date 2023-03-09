#include "headers.h"
#include "treestructure.h"

class Solution
{
    vector<long long> v;
    void levelOrder(TreeNode *root, int lvl = 0)
    {
        if(!root)
            return;
        if(lvl >= v.size())
            v.push_back(root->val);
        else
            v[lvl] += (long long)root->val;
        levelOrder(root->left, lvl + 1);
        levelOrder(root->right, lvl + 1);
    }

public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        levelOrder(root);
        sort(v.begin(), v.end(), greater<long long>());
        return (k - 1 >= v.size()) ? -1 : v[k - 1];
    }
};