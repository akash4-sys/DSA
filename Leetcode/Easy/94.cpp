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


// Morris Inorder Traversal
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        while (root)
        {
            if (!root->left)
                ans.push_back(root->val), root = root->right;
            else
            {
                auto prev = root->left;
                while (prev->right)
                    prev = prev->right;
                prev->right = root;
                auto curr = root;
                root = root->left;
                curr->left = NULL;
            }
        }
        return ans;
    }
};


// Iterative Inorder Traversal
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<int> auxSt{{0}};
        stack<TreeNode *> st{{root}};
        while (!auxSt.empty())
        {
            root = st.top();
            switch (auxSt.top()++)
            {
            case 0:
                if (!root)
                    st.pop(), auxSt.pop();
                break;
            case 1:
                st.push(root->left), auxSt.push(0);
                break;
            case 2:
                ans.push_back(root->val);
                break;
            case 3:
                st.push(root->right), auxSt.push(0);
                break;
            default:
                st.pop(), auxSt.pop();
            }
        }
        return ans;
    }
};

class Solution
{
    vector<int> ans;

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return ans;
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;
    }
};