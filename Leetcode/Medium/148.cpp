#include "../../headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc app=leetcode id=148 lang=cpp

// Merge Sort
class Solution
{
    ListNode *mid(ListNode *head)
    {
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *ans = new ListNode(), *head = ans;
        while(left && right)
        {
            if(left->val < right->val)
                head->next = left, left = left->next;
            else
                head->next = right, right = right->next;
            head = head->next;
        }

        if(left)
            head->next = left;
        if(right)
            head->next = right;
        return ans->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if(!head || !head->next)
            return head;

        ListNode *left = head, *right = mid(head), *temp = right->next;
        right->next = NULL;
        right = temp;

        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};





// Cheat Approach
class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        ListNode *list = new ListNode(0), *h = head, *ans = head;
        vector<int> v;
        int i = 0, j = 0;
        while(head)
        {
            v.push_back(head->val);
            head = head -> next;
            i++;
        }
        sort(begin(v), end(v));
        while(i--)
        {
            list->val = v[j];
            list = list -> next;
            j++;
        }
        return ans;
    }
};