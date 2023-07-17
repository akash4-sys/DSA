#include "../../headers.h"
#include "../../LinkedList.h"

class Solution
{
    ListNode *reverse(ListNode *curr)
    {
        ListNode *prev = NULL;
        while(curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *h1 = reverse(l1), *h2 = reverse(l2), *ans = new ListNode();
        int carry = 0;
        while (h1 || h2)
        {
            int sum = carry;
            if (h1)
                sum += h1->val, h1 = h1->next;
            if (h2)
                sum += h2->val, h2 = h2->next;
            
            carry = sum / 10;
            ans->val = sum % 10;
            auto prev = new ListNode(carry);
            prev->next = ans;
            ans = prev;
        }
        return !carry ? ans->next : ans;
    }
};