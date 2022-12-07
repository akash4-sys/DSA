#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    int i = 0;

public:
    TreeNode *recoverFromPreorder(string &s, int lvl = 0)
    {
        if (i >= s.size())
            return NULL;

        int clvl = 0, n = 0, j = i;
        while (s[j] == '-')
            clvl++, j++;
        while (j < s.size() && s[j] != '-')
            n = (n * 10) + (s[j] - '0'), j++;
        if (lvl > clvl)
            return NULL;

        i = j;
        TreeNode *root = new TreeNode(n);
        root->left = recoverFromPreorder(s, lvl + 1);
        root->right = recoverFromPreorder(s, lvl + 1);
        return root;
    }
};


class Solution
{
public:
    TreeNode *recoverFromPreorder(string s)
    {
        vector<TreeNode *> st;
        for(int i = 0, lvl, n; i < s.size();)
        {
            for(lvl = 0; s[i] == '-'; i++)
                lvl++;
            for(n = 0; i < s.size() && s[i] != '-'; i++)
                n = (n * 10) + (s[i] - '0');

            TreeNode *root = new TreeNode(n);
            while(st.size() > lvl)
                st.pop_back();
            if(!st.empty())
                if(!st.back()->left)
                    st.back()->left = root;
                else
                    st.back()->right = root;
            st.push_back(root);
        }
        return st[0];
    }
};

// @lc app=leetcode id=1028 lang=cpp