#include "../../headers.h"
#include "../../treestructure.h"

// Lengthy Problem

class Solution
{
    bool traverse(TreeNode *r, unordered_map<int, TreeNode *> &mp, int min_left = INT_MIN, int max_right = INT_MAX)
    {
        if (!r)
            return 1;
        if (r->val <= min_left || r->val >= max_right)
            return 0;
        if (!r->left && !r->right)
        {
            if (mp.count(r->val) && mp[r->val] != r)
            {
                r->left = mp[r->val]->left;
                r->right = mp[r->val]->right;
                mp.erase(r->val);
            }
        }
        return traverse(r->left, mp, min_left, r->val) && traverse(r->right, mp, r->val, max_right);
    }

public:
    TreeNode *canMerge(vector<TreeNode *> &trees)
    {
        unordered_map<int, TreeNode *> mp;
        unordered_map<int, int> cnt;
        for (auto &r : trees)
        {
            mp[r->val] = r;
            ++cnt[r->val];
            ++cnt[r->left ? r->left->val : 0];
            ++cnt[r->right ? r->right->val : 0];
        }
        
        for (auto &r : trees)
            if (cnt[r->val] == 1)
                return traverse(r, mp) && mp.size() == 1 ? r : nullptr;
        return nullptr;
    }
};