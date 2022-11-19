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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        if(root) q.push({root, 0});
        while(!q.empty())
        {
            auto [r, lvl] = q.front();
            q.pop();
            if(ans.size() == lvl) ans.push_back({r->val});
            else ans[lvl].push_back(r->val);
            if(r->left) q.push({r->left, lvl + 1});
            if(r->right) q.push({r->right, lvl + 1});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};