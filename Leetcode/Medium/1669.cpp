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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *head = list1, *ans = list1;
        a--;
        b -= a;

        while (a--)
            list1 = list1->next, head = head->next;
        while (b--)
            list1 = list1->next;
        head->next = list2;
        while (list2->next)
            list2 = list2->next;
        list2->next = list1->next;
        return ans;
    }
};