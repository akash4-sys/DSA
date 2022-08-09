#include "../../headers.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// iterative
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *ans = NULL;
        while(head)
        {
            ListNode *temp = head->next;
            head->next = ans;
            ans = head;
            head = temp;
        }
        return ans;
    }
};


// recursive
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if(!head || !head->next)
            return head;
        
        ListNode *ans = reverseList(head->next);
        ans->next->next = head;
        head->next = NULL;
        return ans;
    }
};