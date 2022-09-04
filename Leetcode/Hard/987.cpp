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

// BFS
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes;

        // node, vertical, lvl
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int v = p.second.first, lvl = p.second.second;
            nodes[v][lvl].insert(node->val);
            if (node->left)
                q.push({node->left, {v - 1, lvl + 1}});
            if (node->right)
                q.push({node->right, {v + 1, lvl + 1}});
        }

        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
                col.insert(col.end(), q.second.begin(), q.second.end());
            ans.emplace_back(col);
        }
        return ans;
    }
};

// DFS

class Solution
{
    vector<vector<int>> ans;
    map<int, map<int, multiset<int>>> nodes;
    void dfs(TreeNode *root, int ver, int lvl)
    {
        if (!root)
            return;
        nodes[ver][lvl].insert(root->val);
        dfs(root->left, ver - 1, lvl + 1);
        dfs(root->right, ver + 1, lvl + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        dfs(root, 0, 0);
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
                col.insert(col.end(), q.second.begin(), q.second.end());
            ans.push_back(col);
        }
        return ans;
    }
};