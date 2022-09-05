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

// Time Complexity - O(N), where N is number of nodes in tree
// Space Complexity - O(N^2) -- recursion stack is also there plus map plus answer vector 

class Solution
{
    vector<vector<int>> ans;
    map<int, vector<int>> mp;
    void dfs(Node *root, int lvl)
    {
        if (!root)
            return;
        mp[lvl].push_back(root->val);
        for (int i = 0; i < root->children.size(); i++)
            dfs(root->children[i], lvl + 1);
    }

public:
    vector<vector<int>> levelOrder(Node *root)
    {
        dfs(root, 0);
        for(auto x: mp)
            ans.push_back(x.second);
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
        if(lvl == ans.size())
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