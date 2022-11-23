#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
public:
    int sumNumbers(TreeNode *root, int sum = 0)
    {
        if(!root)
            return 0;
        sum = (sum * 10) + root->val;
        if(!root->left && !root->right)
            return sum;
        return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
    }
};


class Solution
{
    int ans = 0;
    void treePaths(TreeNode *root, string path)
    {
        if(!root)
            return;
        path += to_string(root->val);
        if(!root->left && !root->right)
            ans += stoi(path);
        treePaths(root->left, path);
        treePaths(root->right, path);
        path.pop_back();
    }
public:
    int sumNumbers(TreeNode *root)
    {
        treePaths(root, "");
        return ans;
    }
};