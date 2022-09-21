#include "../../headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int dp[9] = {0};
    void gen(int n)
    {
        if(n <= 1)
    }

public:
    vector<TreeNode*> generateTrees(int n) 
    {
        gen(n);   
    }
};