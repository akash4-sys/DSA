#include "../../headers.h"
#include "../../treestructure.h"

// @ Although this question can be done in many ways using the some popular tricks the reason why most solution doesn't work
// @ is becoz when converted to string it's impossible to tell the difference between two digit and one digit numbers until there's
// @ something in b/w. I wasted a lot of time coz of this.

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        return root ? to_string(root->val) + "-" + serialize(root->left) + serialize(root->right) : "";
    }

    TreeNode *tree(TreeNode *root, int v)
    {
        if(!root)
        {
            TreeNode *temp = new TreeNode(v);
            return temp;
        }
        if(root->val <= v)
            root->right = tree(root->right, v);
        else
            root->left = tree(root->left, v);
        return root;
    }

    TreeNode *deserialize (string pre)
    {
        stringstream s(pre);
        string num;
        TreeNode *root = NULL;
        while(getline(s, num, '-'))
            root = tree(root, stoi(num));
        return root;
    }
};


// @lc app=leetcode id=449 lang=cpp