#include "../../headers.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *ans = new ListNode(), *h = ans;

        head = head->next;
        int sum = 0;

        for (; head; head = head->next)
        {
            if (head->val)
                sum += head->val;
            else
            {
                ListNode *temp = new ListNode();
                temp->val = sum;
                ans->next = temp;
                ans = ans->next;
                sum = 0;
            }
        }
        return h->next;
    }
};




// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    ListNode *mergeNodes(ListNode *st)
    {
        for(ListNode *h = st, *head = st->next; head; head = head->next)
        {
            if(head->val)
                h->val += head->val;
            else
            {
                h->next = (head->next != nullptr) ? head : nullptr;
                h = head;
            }
        }
        return st;
    }
};