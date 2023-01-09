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

// Morris Traversal
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        while (root)
        {
            if (!root->left)
            {
                ans.push_back(root->val);
                root = root->right;
            }
            else
            {
                auto prev = root->left;
                while (prev->right && prev->right != root)      // find the rightmost child
                    prev = prev->right;
                
                if (prev->right)                // exit the loop in tree
                    prev->right = NULL, root = root->right;
                else            // create thread
                {
                    prev->right = root;
                    ans.push_back(root->val);
                    root = root->left;
                }
            }
        }
        return ans;
    }
};



// Iterative PreOrder Traversal
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
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
                ans.push_back(root->val);
                break;
            case 2:
                st.push(root->left), auxSt.push(0);
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};