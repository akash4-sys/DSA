#include "../../headers.h"
#include "../../treestructure.h"
#include "../../LinkedList.h"

// Time Complexity - O(N)
// Space Complexity - O(N)
class Solution
{
    TreeNode *BST(vector<int> &v, int l, int r)
    {
        if (l >= r)
            return NULL;
        int mid = (l + r) / 2;
        TreeNode *root = new TreeNode(v[mid]);
        root->left = BST(v, l, mid);
        root->right = BST(v, mid + 1, r);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        vector<int> v;
        for (; head; head = head->next)
            v.push_back(head->val);
        return BST(v, 0, v.size());
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    ListNode *head;
    TreeNode *BST(int l, int r)
    {
        if (l >= r)
            return NULL;

        int mid = (l + r) / 2;
        auto left = BST(l, mid);

        TreeNode *root = new TreeNode(head->val);
        root->left = left;
        head = head->next;

        root->right = BST(mid + 1, r);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        int size = 0;
        this->head = head;
        for (auto h = head; h; h = h->next, size++);
        return BST(0, size);
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N)
class Solution
{
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode *tail = NULL)
    {
        if (head == tail)
            return NULL;
        if (head->next == tail)
            return new TreeNode(head->val);

        ListNode *mid = head, *fast = head->next;
        while (fast != tail && fast->next != tail)
            mid = mid->next, fast = fast->next->next;

        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head, mid);
        root->right = sortedListToBST(mid->next, tail);
        return root;
    }
};


// @lc app=leetcode id=109 lang=cpp