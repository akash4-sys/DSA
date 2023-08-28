#include "../../headers.h"
#include "../../LinkedList.h"

class Solution
{
public:
    ListNode* partition(ListNode* head, int x)
    {
        auto *sm = new ListNode(), *gt = new ListNode();
        auto *l = sm, *r = gt;
        for (; head; head = head->next)
            if (head->val < x)
               l = l->next = head;
            else
                r = r->next = head;
        
        r->next = NULL;
        l->next = gt->next;
        return sm->next;
    }
};