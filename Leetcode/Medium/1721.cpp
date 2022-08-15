#include "../../headers.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *h1 = nullptr, *h2 = nullptr;
        for(auto curr = head; curr != nullptr; curr = curr->next)
        {
            h2 = (h2 == nullptr) ? nullptr : h2->next;
            if(--k == 0)
            {
                h1 = curr;
                h2 = head;
            }
        }
        swap(h1->val, h2->val);
        return head;
    }
};