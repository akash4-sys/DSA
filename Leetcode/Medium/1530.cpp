#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    int ans = 0;
    vector<int> dfs(TreeNode *root, int d)
    {
        if(!root)
            return {};
        if(!root->left && !root->right)
            return {1};

        auto left = dfs(root->left, d), right = dfs(root->right, d);
        for(auto r: right)
            for(auto l: left)
                ans += (l + r <= d);
        
        for(int i = 0; i < left.size(); i++)
            left[i]++;
        for(int i = 0; i < right.size(); i++)
            left.push_back(++right[i]);
        return left;
    }

public:
    int countPairs(TreeNode *root, int d)
    {
        dfs(root, d);
        return ans;
    }
};