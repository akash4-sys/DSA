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
public:

    vector<TreeNode*> store;
    void recur(TreeNode* curr){
        if (!curr) return;
        store.push_back(curr);
        
        recur(curr -> left);
        recur(curr -> right);
    }
    void flatten(TreeNode* root) {
        if (!root) return;
        
        recur(root);
        for (int i = 0; i < store.size() - 1; ++ i){
            store[i] -> right = store[i + 1];
            store[i] -> left = nullptr;
        }
    }
};