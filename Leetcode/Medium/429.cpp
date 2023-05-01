#include "../../headers.h"

class Node
{
public:
    int val;
    vector<Node *> children;
    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node *> _children) : val(_val), children(_children) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        queue<Node *> q;
        if (root)
            q.push(root);
        
        for (int lvl = 0; !q.empty(); lvl++)
        {
            ans.push_back({});
            for (int k = q.size(); k; k--)
            {
                auto r = q.front();
                q.pop();
                ans[lvl].push_back(r->val);
                for (auto c : r->children)
                    q.push(c);
            }
        }
        return ans;
    }
};

// Time Complexity - O(N), where N is number of nodes in tree
// Space Complexity - O(H), where H is height of tree in recursion stack
class Solution
{
    vector<vector<int>> ans;
    void dfs(Node *root, int lvl)
    {
        if (!root)
            return;
        if (lvl == ans.size())
            ans.push_back({});
        ans[lvl].push_back(root->val);
        for (int i = 0; i < root->children.size(); i++)
            dfs(root->children[i], lvl + 1);
    }

public:
    vector<vector<int>> levelOrder(Node *root)
    {
        dfs(root, 0);
        return ans;
    }
};