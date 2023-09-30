#include "../../headers.h"
#include "../../LinkedList.h"

class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        ListNode *h = head;
        if (head->val > 4)
            h = new ListNode(1), h->next = head;
        
        for (; head; head = head->next)
        {
            int curr = (head->val * 2) % 10;
            curr += (head->next && head->next->val > 4);
            head->val = curr;
        }
        return h;
    }
};