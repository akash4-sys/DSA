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
    int ans = 0;

public:
    int pseudoPalindromicPaths(TreeNode *root, int x = 0)
    {
        if (root)
        {
            x = x ^ (1 << root->val);
            ans += (!root->left && !root->right && (x & (x - 1)) == 0);
            pseudoPalindromicPaths(root->right, x);
            pseudoPalindromicPaths(root->left, x);
        }
        return ans;
    }
};

class Solution
{
    int cnt[10] = {0};
public:
    int pseudoPalindromicPaths(TreeNode *root, int odds = 0)
    {
        int ans = 0;
        if (root)
        {
            odds += ++cnt[root->val] % 2 ? 1 : -1;
            if (!root->right && !root->left)
                ans = odds < 2;
            else
                ans = pseudoPalindromicPaths(root->left, odds) + pseudoPalindromicPaths(root->right, odds);
            odds += --cnt[root->val] % 2 ? -1 : 1;
        }
        return ans;
    }
};