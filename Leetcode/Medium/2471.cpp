#include "headers.h"

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
    vector<vector<int>> tree;
    void dfs(TreeNode *root, int lvl)
    {
        if (!root) return;
        if (lvl == tree.size())
            tree.push_back({root->val});
        else
            tree[lvl].push_back(root->val);
        dfs(root->left, lvl + 1);
        dfs(root->right, lvl + 1);
    }

public:
    int minimumOperations(TreeNode *root)
    {
        int ans = 0;
        dfs(root, 0);
        for(auto &lvl : tree)
        {
            int c = 0;
            map<int, int> mp;
            for(int i = 0; i < lvl.size(); i++)
                mp[lvl[i]] = i;
            
            int j = 0;
            for(auto &[val, i]: mp)
            {
                if(i != j)
                {
                    ans++;
                    mp[lvl[j]] = i;
                    swap(lvl[j], lvl[i]);       //not necessary
                    i = j;
                }
                j++;
            }
        }
        return ans;
    }
};