#include "../../headers.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// O(n^2) time complexity
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;

        ListNode *curr = head;
        int len = 0;
        while (curr)
            len++, curr = curr->next;

        k %= len;

        while (k--)
        {
            ListNode *h = head, *temp;
            while (head->next)
            {
                if (!head->next->next)
                    temp = head;
                head = head->next;
            }
            head->next = h;
            temp->next = NULL;
        }
        return head;
    }
};

// O(n)
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;

        ListNode *curr = head;
        int len = 0;
        while (curr)
            len++, curr = curr->next;

        k %= len;
        if (k == 0)
            return head;

        auto h = head, t = head;
        while (k--)
            t = t->next;
        while (t->next)
            h = h->next, t = t->next;
        auto ans = h->next;
        h->next = nullptr;
        t->next = head;
        return ans;
    }
};