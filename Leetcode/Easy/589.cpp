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
    vector<int> preorder(Node *root)
    {
        if (!root)
            return {};
        vector<int> ans = {root->val};
        for (auto r : root->children)
        {
            auto v = preorder(r);
            ans.insert(ans.end(), v.begin(), v.end());
        }
        return ans;
    }
};