#include "../../headers.h"
#include "../../LinkedList.h"

class Solution
{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (!head->next)
            return head;
            
        auto prev = head, curr = head->next;
        while (curr)
        {
            int g = gcd(prev->val, curr->val);
            prev->next = new ListNode(g);
            prev->next->next = curr;
            prev = prev->next->next;
            curr = curr->next;
        }
        return head;
    }
};