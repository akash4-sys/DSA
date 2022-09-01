#include "../../headers.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int goodNodes(TreeNode *root, int prev = INT_MIN)
    {
        int ans = 0;
        if(!root)
            return 0;
        if(root->val >= prev)
            ans++, prev = root->val;
        ans += goodNodes(root->right, prev);
        ans += goodNodes(root->left, prev);
        return ans;
    }
};