#include "../../headers.h"
#include "../../treestructure.h"

class Codec
{
    TreeNode *buildTree(stringstream &ss)
    {
        string s;
        getline(ss, s, ',');
        if(s == "#")
            return NULL;
        TreeNode *root = new TreeNode(stoi(s));
        root->left = buildTree(ss);
        root->right = buildTree(ss);
        return root;
    }

public:
    string serialize(TreeNode *root)
    {
        if(!root)
            return "#";
        return to_string(root->val) + ',' + serialize(root->left) + ',' + serialize(root->right);
    }

    TreeNode *deserialize(string data)
    {
        if(data == "#")
            return NULL;
        stringstream s(data);
        return buildTree(s);
    }
};


// @lc app=leetcode id=297 lang=cpp