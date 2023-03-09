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

// @ level order traversal
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if(root) q.push(root);
        while(!q.empty())
        {
            int k = q.size();
            ans.push_back({});
            while(k--)
            {
                auto *r = q.front();
                q.pop();
                ans[ans.size() - 1].push_back(r->val);
                if(r->left) q.push(r->left);
                if(r->right) q.push(r->right);
            }
        }
        return ans;
    }
};



class Solution
{
    vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrder(TreeNode *root, int lvl = 0)
    {
        if(!root)
            return {};
        if(lvl >= ans.size())
            ans.push_back({root->val});
        else
            ans[lvl].push_back(root->val);
        levelOrder(root->left, lvl + 1);
        levelOrder(root->right, lvl + 1);
        return ans;
    }
};