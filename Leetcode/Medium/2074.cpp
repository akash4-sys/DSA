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
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        ListNode ans, *h = &ans, *c = head;
        int s = 0;
        while (c)
            ++s, c = c->next;

        for (int i = 1; head; i++)
        {
            int len = min(s, i);
            ListNode *tail = NULL;
            for (int j = 0; j < len && head; j++)
            {
                ListNode *prev = head;
                head = head->next;
                if (len % 2)
                {
                    h->next = prev;
                    h = prev;
                }
                else
                {
                    if (!tail)
                        tail = prev;
                    prev->next = h->next;
                    h->next = prev;
                }
            }
            if (tail)
                h = tail;
            s -= len;
        }
        h->next = NULL;
        return ans.next;
    }
};