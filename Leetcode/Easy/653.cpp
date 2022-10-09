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

// Time complexity O(N)
// Space complexity O(N)

class Solution
{
    unordered_set<int> s;
public:
    bool findTarget(TreeNode *root, int k)
    {
        if(!root)
            return false;
        if(s.count(k - root->val))
            return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};



// Time complexity O(NH) -- H is height of tree
// Space complexity O(N)
// Recursive solution is not worth it
class Solution
{
    bool search(TreeNode *root, TreeNode *curr, int k)
    {
        if (!root)
            return 0;
        return (root->val == k) && (root != curr) || (root->val < k) && search(root->right, curr, k) || (root->val > k) && search(root->left, curr, k);
    }

    bool dfs(TreeNode *root, TreeNode *curr, int k)
    {
        if (!curr)
            return false;
        return search(root, curr, k - curr->val) || dfs(root, curr->left, k) || dfs(root, curr->right, k);
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        return dfs(root, root, k);
    }
};