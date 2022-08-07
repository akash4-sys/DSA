#include "../../headers.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Time complexity O(N)
// O(1) Space

class Solution
{
public:

    ListNode *reverse(ListNode *head)
    {
        ListNode dummy(0);
        while(head)
        {
            ListNode *node = head;
            head = head->next;
            node->next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }

    bool isPalindrome(ListNode *head)
    {
        ListNode *l = head;
        int len = 0;
        for (; l; l = l->next, len++);
        if(len == 1)
            return true;
        int mid = (len + 1) / 2;

        ListNode *h = head, *rev;
        while(--mid > 0)
            h = h->next;
        
        rev = h->next;
        h->next = NULL;
        
        rev = reverse(rev);
        while(head && rev)
        {
            if(head->val != rev->val)
                return false;
            
            head = head->next;
            rev = rev->next;
        }
        
        return true;
    }
};




// Time Complexity O(N)
// Space Complexity O(N)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> st;
        ListNode *h = head;
        while(head)
        {
            st.push(head);
            head = head->next;
        }

        while(h)
        {
            if(h->val != st.top()->val)
                return false;
        }
        return true;
    }
};