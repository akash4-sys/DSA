#include "../../headers.h"
#include "../../treestructure.h"
#include "../../LinkedList.h"

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail = NULL)
    {
        if(head == tail)
            return NULL;
        
        if(head->next == tail)
        {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }

        ListNode *mid = head, *fast = head->next;
        while(fast != tail && fast->next != tail)
            mid = mid->next, fast = fast->next->next;

        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head, mid);
        root->right = sortedListToBST(mid->next, tail);
        return root;
    }
};


// @lc app=leetcode id=109 lang=cpp