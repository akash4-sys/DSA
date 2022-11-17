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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
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
            if((ans.size() - 1) % 2)
                reverse(ans[ans.size() - 1].begin(), ans[ans.size() - 1].end());
        }
        return ans;
    }
};



class Solution
{
    vector<vector<int>> ans;
    void zigzagLevelOrder(TreeNode *root, int lvl)
    {
        if(!root)
            return;
        if(lvl >= ans.size()) ans.push_back({root->val});
        else ans[lvl].push_back(root->val);            
        zigzagLevelOrder(root->left, lvl + 1);
        zigzagLevelOrder(root->right, lvl + 1);
        return;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        zigzagLevelOrder(root, 0);
        for(int i = 1; i < ans.size(); i++)
            if(i % 2)
                reverse(ans[i].begin(), ans[i].end());
        return ans;
    }
};