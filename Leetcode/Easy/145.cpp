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

// Iterative postorder traversal
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
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
                case 1: st.push(root->left), auxSt.push(0);
                    break;
                case 2: st.push(root->right), auxSt.push(0);
                    break;
                case 3: ans.push_back(root->val);
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        if(!root)
            return {};
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};