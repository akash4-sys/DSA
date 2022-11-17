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

// Iterative PreOrder Traversal
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<int> auxSt{{0}};
        stack<TreeNode*> st{{root}};
        while(!auxSt.empty())
        {
            root = st.top();
            switch(auxSt.top()++)
            {
                case 0: if(!root) st.pop(), auxSt.pop();
                    break;
                case 1: ans.push_back(root->val);
                    break;
                case 2: st.push(root->left), auxSt.push(0);
                    break;
                case 3: st.push(root->right), auxSt.push(0);
                    break;
                default: st.pop(), auxSt.pop();
            }
        }
        return ans;
    }
};


class Solution
{
    vector<int> ans;
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        if(!root)
            return {};
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};